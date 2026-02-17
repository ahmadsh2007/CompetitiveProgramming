"""
bench_cpp.py

- Compiles a C++ file (default: file.cpp)
- Runs it (n + 1) times
- Measures each run time and averages runs #2..#(n+1) (skips the first warmup run)
- Feeds stdin from input.txt and checks stdout equals output.txt

Key behavior:
- No matter where you run this script from, it always switches to *its own directory*,
  so input/output/cpp paths stay stable relative to the script location.
"""

from __future__ import annotations

import argparse
import os
import shlex
import subprocess
import sys
import time
from pathlib import Path


def normalize_output(s: str, ignore_trailing_ws: bool) -> str:
    # Normalize line endings across OS
    s = s.replace("\r\n", "\n").replace("\r", "\n")
    if ignore_trailing_ws:
        s = "\n".join(line.rstrip() for line in s.split("\n"))
    return s.rstrip("\n")


def run_program(exe_path: Path, input_text: str, timeout: float | None) -> tuple[float, str, str, int]:
    start = time.perf_counter_ns()
    p = subprocess.run(
        [str(exe_path)],
        input=input_text,
        text=True,
        capture_output=True,
        timeout=timeout,
    )
    end = time.perf_counter_ns()
    elapsed_ms = (end - start) / 1_000_000.0
    return elapsed_ms, p.stdout, p.stderr, p.returncode


def main() -> int:
    parser = argparse.ArgumentParser(description="Compile + run C++ (n+1) times, skip first in average, verify output.")
    parser.add_argument(
        "-n", 
        type=int, 
        default=10, 
        help="Number of timed runs to average (script runs n+1 total). Default: 10"
        )
    parser.add_argument(
        "--cpp",
        help="C++ source file path. Default: file.cpp"
        )
    parser.add_argument(
        "--in",
        dest="infile",
        default="Utils/input.txt",
        help="Input file path. Default: input.txt"
        )
    parser.add_argument(
        "--out",
        dest="outfile",
        default="Utils/output.txt",
        help="Expected output file path. Default: output.txt")
    parser.add_argument(
        "--compiler",
        default="g++",
        help="Compiler command. Default: g++")
    parser.add_argument(
        "--cflags",
        default="-O2 -std=gnu++23 -DONLINE_JUDGE",
        help='Compiler flags (string). Default: "-O2 -std=gnu++17 -DONLINE_JUDGE"',
    )
    parser.add_argument(
        "--timeout",
        type=float,
        default=2.0,
        help="Per-run timeout seconds. Default: 2.0 (more Codeforces-like; override per problem)",
    )
    parser.add_argument(
        "--no-timeout",
        action="store_true",
        help="Disable timeout")
    parser.add_argument(
        "--ignore-trailing-ws",
        dest="ignore_trailing_ws",
        action="store_true",
        default=True,
        help="Ignore trailing whitespace differences per line (default: ON, CF-ish)",
    )
    parser.add_argument(
        "--strict-ws",
        dest="ignore_trailing_ws",
        action="store_false",
        help="Strict whitespace (disable ignoring trailing whitespace)",
    )
    parser.add_argument(
        "--keep-going",
        action="store_true",
        help="If output mismatch occurs, keep timing runs anyway (still reports mismatch)",
    )
    args = parser.parse_args()

    if args.n < 1:
        print("n must be >= 1", file=sys.stderr)
        return 2

    script_dir = Path(__file__).resolve().parent
    os.chdir(script_dir)

    def resolve_from_script_dir(p: str) -> Path:
        path = Path(p)
        return path if path.is_absolute() else (script_dir / path)

    cpp_path = resolve_from_script_dir(args.cpp).resolve()
    in_path = resolve_from_script_dir(args.infile).resolve()
    out_path = resolve_from_script_dir(args.outfile).resolve()

    if not cpp_path.exists():
        print(f"Missing C++ file: {cpp_path}", file=sys.stderr)
        return 2
    if not in_path.exists():
        print(f"Missing input file: {in_path}", file=sys.stderr)
        return 2
    if not out_path.exists():
        print(f"Missing output file: {out_path}", file=sys.stderr)
        return 2

    input_text = in_path.read_text(encoding="utf-8", errors="replace")
    expected_raw = out_path.read_text(encoding="utf-8", errors="replace")
    expected = normalize_output(expected_raw, args.ignore_trailing_ws)

    build_dir = script_dir / "build"
    build_dir.mkdir(exist_ok=True)

    exe_name = cpp_path.stem + (".exe" if os.name == "nt" else "")
    exe_path = (build_dir / exe_name).resolve()

    compile_cmd = [args.compiler] + shlex.split(args.cflags) + [str(cpp_path), "-o", str(exe_path)]
    print("Compiling:", " ".join(shlex.quote(x) for x in compile_cmd))
    comp = subprocess.run(compile_cmd, text=True, capture_output=True)
    if comp.returncode != 0:
        print("Compilation failed.\n--- stdout ---\n" + comp.stdout + "\n--- stderr ---\n" + comp.stderr, file=sys.stderr)
        return 1

    timeout = None if args.no_timeout else args.timeout

    total_runs = args.n + 1  # warmup + n timed
    times_ms: list[float] = []
    mismatch_found = False

    print(f"\nRunning {total_runs} times (warmup + {args.n} timed). Skipping run #1 in the average.\n")

    for i in range(1, total_runs + 1):
        label = f"Warmup #{i}" if i == 1 else f"Run #{i-1}"

        try:
            t_ms, stdout, stderr, code = run_program(exe_path, input_text, timeout)
        except subprocess.TimeoutExpired:
            print(f"{label}: TIMEOUT after {timeout}s", file=sys.stderr)
            return 1

        got = normalize_output(stdout, args.ignore_trailing_ws)
        ok = (code == 0) and (got == expected)

        status = "OK" if ok else "FAIL"
        print(f"{label:>10}: {t_ms:>10.3f} ms   [{status}]   exit={code}")

        if not ok:
            mismatch_found = True
            if code != 0:
                print("\n--- Program stderr ---\n" + stderr, file=sys.stderr)

            print("\n--- Expected (first 400 chars) ---")
            print(expected[:400])
            print("\n--- Got (first 400 chars) ---")
            print(got[:400])

            if not args.keep_going:
                print("\nStopping due to mismatch. (Use --keep-going to continue timing anyway.)", file=sys.stderr)
                return 1

        times_ms.append(t_ms)

    timed = times_ms[1:]
    avg_ms = sum(timed) / len(timed)

    print("\nSummary")
    print(f"- Warmup run #1: {times_ms[0]:.3f} ms (excluded)")
    print(f"- Timed runs: {len(timed)}")
    print(f"- Average (runs #2..#{total_runs}): {avg_ms:.3f} ms")
    print(f"- Output check: {'PASSED' if not mismatch_found else 'FAILED (see above)'}")

    return 0 if not mismatch_found else 1


if __name__ == "__main__":
    raise SystemExit(main())