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

RED = "\033[31m"
GREEN = "\033[32m"
RESET = "\033[0m"

# Optional additions for better logs:
YELLOW = "\033[33m"
BOLD = "\033[1m"

def normalize_output(s: str, ignore_trailing_ws: bool) -> str:
    # Normalize line endings across OS
    s = s.replace("\r\n", "\n").replace("\r", "\n")
    if ignore_trailing_ws:
        s = "\n".join(line.rstrip() for line in s.split("\n"))
    return s.rstrip("\n")


def run_program(exe_path: Path, input_text: str, timeout: float | None) -> tuple[float, str, str, int, float]:
    cmd = [str(exe_path)]
    time_tool = None

    if sys.platform == "linux" and os.path.exists("/usr/bin/time"):
        cmd = ["/usr/bin/time", "-f", "%M", str(exe_path)]
        time_tool = "linux"
    elif sys.platform == "darwin" and os.path.exists("/usr/bin/time"):
        cmd = ["/usr/bin/time", "-l", str(exe_path)]
        time_tool = "mac"

    start = time.perf_counter_ns()
    
    with subprocess.Popen(
        cmd,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    ) as p:
        try:
            stdout, stderr = p.communicate(input=input_text, timeout=timeout)
        except subprocess.TimeoutExpired:
            p.kill()
            stdout, stderr = p.communicate()
            raise subprocess.TimeoutExpired(p.args, timeout, output=stdout, stderr=stderr)
        
        peak_mem_mb = 0.0
        
        # Cross-Platform Peak Working Set Retrieval
        if sys.platform == "win32":
            import ctypes
            from ctypes import wintypes
            class PROCESS_MEMORY_COUNTERS(ctypes.Structure):
                _fields_ = [
                    ("cb", wintypes.DWORD),
                    ("PageFaultCount", wintypes.DWORD),
                    ("PeakWorkingSetSize", ctypes.c_size_t),
                    ("WorkingSetSize", ctypes.c_size_t),
                    ("QuotaPeakPagedPoolUsage", ctypes.c_size_t),
                    ("QuotaPagedPoolUsage", ctypes.c_size_t),
                    ("QuotaPeakNonPagedPoolUsage", ctypes.c_size_t),
                    ("QuotaNonPagedPoolUsage", ctypes.c_size_t),
                    ("PagefileUsage", ctypes.c_size_t),
                    ("PeakPagefileUsage", ctypes.c_size_t),
                ]
            counters = PROCESS_MEMORY_COUNTERS()
            counters.cb = ctypes.sizeof(counters)
            psapi = ctypes.WinDLL('psapi')
            # Fetch from active handle before Popen goes out of scope and is Garbage Collected
            if psapi.GetProcessMemoryInfo(int(p._handle), ctypes.byref(counters), counters.cb):
                peak_mem_mb = counters.PeakWorkingSetSize / (1024 * 1024)

    end = time.perf_counter_ns()
    elapsed_ms = (end - start) / 1_000_000.0

    # Parse stderr for Unix based timing tools where the overhead prints alongside standard output
    if time_tool == "linux":
        lines = stderr.strip('\r\n').split('\n')
        if lines:
            try:
                # /usr/bin/time -f "%M" outputs Peak RSS in KB
                peak_mem_mb = float(lines[-1].strip()) / 1024.0
                stderr = '\n'.join(lines[:-1])
                if stderr: stderr += '\n'
            except ValueError:
                pass
    elif time_tool == "mac":
        lines = stderr.split('\n')
        clean_stderr = []
        for line in lines:
            if 'maximum resident set size' in line:
                try:
                    # mac outputs in bytes
                    peak_mem_mb = float(line.split()[0]) / (1024 * 1024)
                except ValueError:
                    pass
            elif line.strip().endswith('real') or line.strip().endswith('user') or line.strip().endswith('sys') or "maximum resident set size" in line:
                continue
            else:
                clean_stderr.append(line)
        stderr = '\n'.join(clean_stderr)

    return elapsed_ms, stdout, stderr, p.returncode, peak_mem_mb

def main() -> int:
    parser = argparse.ArgumentParser(
        description="Compile + run C++ (n+1) times, skip first in average, verify output & memory."
        )
    parser.add_argument(
        "-n", 
        type=int, 
        default=10, 
        help="Number of timed runs to average (script runs n+1 total). Default: 10"
        )
    parser.add_argument(
        "--cpp",
        default="file.cpp",
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
        default="g++-15",
        help="Compiler command. Default: g++-15")
    parser.add_argument(
        "--cflags",
        default="-O2 -std=gnu++23 -DONLINE_JUDGE",
        help='Compiler flags (string). Default: "-O2 -std=gnu++23 -DONLINE_JUDGE"'
        )
    parser.add_argument(
        "--timeout",
        type=float,
        default=2.0,
        help="Per-run timeout seconds. Default: 2.0 (more Codeforces-like; override per problem)"
        )
    parser.add_argument(
        "--mem-limit",
        type=float,
        default=256.0,
        help="Memory Limit Exceeded (MLE) threshold in MB. Default: 256.0 (Codeforces default)"
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
        help="Ignore trailing whitespace differences per line (default: ON, CF-ish)"
        )
    parser.add_argument(
        "--strict-ws",
        dest="ignore_trailing_ws",
        action="store_false",
        help="Strict whitespace (disable ignoring trailing whitespace)"
        )
    parser.add_argument(
        "--keep-going",
        action="store_true",
        help="If output mismatch occurs, keep timing runs anyway (still reports mismatch)"
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

    build_dir = script_dir / "bin"
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
    mems_mb: list[float] = []
    mismatch_found = False

    print(f"\nRunning {total_runs} times (warmup + {args.n} timed). Skipping run #1 in the average.\n")

    for i in range(1, total_runs + 1):
        # width = len(str(args.n))
        # * If you want to format the Run # more, uncomment what's above and change the label from:
        # * else f"Run #{i-1}" to: else f"Run #{i-1:0{width}d}"
        label = f"Warmup #{i}" if i == 1 else f"Run #{i-1}"

        try:
            t_ms, stdout, stderr, code, mem_mb = run_program(exe_path, input_text, timeout)
        except subprocess.TimeoutExpired:
            print(f"{label:>10}: TIMEOUT after {timeout}s", file=sys.stderr)
            return 1

        got = normalize_output(stdout, args.ignore_trailing_ws)
        ok = (code == 0) and (got == expected) and (mem_mb <= args.mem_limit)

        if mem_mb > args.mem_limit:
            status = "MLE"
            color = RED
        elif code != 0:
            status = "RE"
            color = RED
        elif got != expected:
            status = "WA"
            color = RED
        else:
            status = "OK"
            color = GREEN

        print(f"{label:>10}: {t_ms:>10.3f} ms  |  {mem_mb:>6.2f} MB   [{color}{status}{RESET}]   exit={code}")

        if not ok:
            mismatch_found = True
            if status == "MLE":
                print(f"\n--- Memory Limit Exceeded! Used {RED}{mem_mb:.2f} MB{RESET} > {YELLOW}{args.mem_limit:.2f} MB{RESET} ---", file=sys.stderr)
            elif code != 0:
                print("\n--- Program stderr ---\n" + stderr, file=sys.stderr)
            elif status == "WA":
                print("\n--- Expected (first 400 chars) ---")
                print(expected[:400])
                print("\n--- Got (first 400 chars) ---")
                print(got[:400])

            if not args.keep_going:
                print(f"\n{RED}{BOLD}Stopping due to mismatch.{RESET} (Use {YELLOW}--keep-going{RESET} to continue timing anyway.)", file=sys.stderr)
                return 1

        times_ms.append(t_ms)
        mems_mb.append(mem_mb)

    timed = times_ms[1:]
    avg_ms = sum(timed) / len(timed)
    peak_mem_overall = max(mems_mb)

    print("\nSummary")
    print(f"- Warmup run #1: {times_ms[0]:.3f} ms (excluded)")
    print(f"- Timed runs: {len(timed)}")
    print(f"- Average (runs #2..#{total_runs}): {GREEN}{avg_ms:.3f} ms{RESET}")
    print(f"- Peak Memory: {GREEN}{peak_mem_overall:.2f} MB{RESET}")
    print(f"- Output check: {f'{GREEN}PASSED{RESET}' if not mismatch_found else f'{RED}FAILED{RESET} (see above)'}")

    return 0 if not mismatch_found else 1


if __name__ == "__main__":
    raise SystemExit(main())