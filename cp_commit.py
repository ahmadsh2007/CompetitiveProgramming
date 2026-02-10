import os
import sys
import subprocess
import json
import shlex
import argparse
import tempfile
from datetime import datetime

COUNTER_FILE = ".cp_counter"

RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
CYAN = "\033[36m"
RESET = "\033[0m"


def run(cmd: str, capture: bool = False) -> subprocess.CompletedProcess:
    return subprocess.run(
        cmd,
        shell=True,
        text=True,
        capture_output=capture
    )


def ensure_git_repo():
    res = run("git rev-parse --is-inside-work-tree", capture=True)
    if res.returncode != 0 or (res.stdout or "").strip() != "true":
        print(f"{RED}❌ Not inside a Git repository.{RESET}")
        sys.exit(1)


def load_data():
    if not os.path.exists(COUNTER_FILE):
        return {
            "start_date": datetime.today().strftime("%Y-%m-%d"),
            "work_days": [],
            "daily_commits": {}
        }
    with open(COUNTER_FILE, "r") as f:
        return json.load(f)


def save_data(data):
    with open(COUNTER_FILE, "w") as f:
        json.dump(data, f)


def get_changed_files():
    res = run("git status --porcelain", capture=True)
    lines = [ln for ln in (res.stdout or "").splitlines() if ln.strip()]
    files = []
    for ln in lines:
        path_part = ln[3:].strip()
        if " -> " in path_part:
            path_part = path_part.split(" -> ", 1)[1].strip()
        files.append(path_part)
    return files


def has_upstream() -> bool:
    res = run("git rev-parse --abbrev-ref --symbolic-full-name @{u}", capture=True)
    return res.returncode == 0 and (res.stdout or "").strip() != ""


def behind_count() -> int:
    res = run("git rev-list --count HEAD..@{u}", capture=True)
    if res.returncode != 0:
        return 0
    try:
        return int((res.stdout or "0").strip())
    except ValueError:
        return 0


def pull_if_needed():
    if not has_upstream():
        print(f"{YELLOW}⚠️  No upstream set (branch not tracking remote). Skipping pull.{RESET}")
        return

    # fast check first
    run("git fetch --quiet")
    b = behind_count()
    if b > 0:
        print(f"{CYAN}🔄 Remote ahead by {b} commit(s) — pulling (rebase + autostash)...{RESET}")
        res = run("git pull --rebase --autostash")
        if res.returncode != 0:
            print(f"{RED}❌ Pull/rebase failed (likely conflicts). Resolve, then run again.{RESET}")
            sys.exit(res.returncode)
    else:
        print(f"{CYAN}✅ Up to date — no pull needed.{RESET}")


def compute_commit_fields(data):
    start_date = datetime.strptime(data["start_date"], "%Y-%m-%d").date()
    today = datetime.today().date()

    day_number = (today - start_date).days + 1
    today_str = today.strftime("%Y-%m-%d")

    if today_str not in data["work_days"]:
        data["work_days"].append(today_str)
        data["work_days"].sort()

    work_day_number = data["work_days"].index(today_str) + 1
    commits_today_next = data["daily_commits"].get(today_str, 0) + 1

    msg = f"Day {day_number:03d} Work Day {work_day_number:03d} Commit {commits_today_next:02d}"
    return msg, today_str, day_number, work_day_number, commits_today_next


def edit_commit_message(default_msg: str) -> str:
    """
    Opens your editor once and returns the edited message.
    Uses $GIT_EDITOR, then $EDITOR, else vi.
    """
    editor = os.environ.get("GIT_EDITOR") or os.environ.get("EDITOR") or "vi"

    with tempfile.NamedTemporaryFile(mode="w+", delete=False, suffix=".msg") as tf:
        tf.write(default_msg + "\n")
        tf.flush()
        path = tf.name

    run(f"{editor} {shlex.quote(path)}")

    with open(path, "r") as f:
        new_msg = f.read().strip()

    try:
        os.remove(path)
    except OSError:
        pass

    return new_msg if new_msg else default_msg


def stage_menu_and_maybe_edit_msg(msg_ref: dict):
    """
    Single place for:
      - choose staging mode [Enter]/p/f
      - OR press e to edit commit message
    So you never have to press e twice across multiple prompts.
    """
    files = get_changed_files()
    if not files:
        print(f"{YELLOW}⚠️  No changes detected — commit skipped.{RESET}")
        sys.exit(0)

    while True:
        print(f"{CYAN}🧾 Changes detected:{RESET}")
        for i, f in enumerate(files, 1):
            print(f"  {i:>2}. {f}")

        print("\nOptions (one prompt only):")
        print("  [Enter] Stage ALL changes and continue")
        print("  [p]     Patch mode (pick hunks)  -> git add -p")
        print("  [f]     Choose files to stage (e.g. 1,3,4 or 1-5,7)")
        print("  [e]     Edit commit message")
        choice = input("Choose: ").strip().lower()

        if choice == "e":
            msg_ref["msg"] = edit_commit_message(msg_ref["msg"])
            print(f"\n{CYAN}📌 Updated commit message:{RESET}")
            print(f'   "{msg_ref["msg"]}"\n')
            continue

        if choice == "":
            res = run("git add --all")
            if res.returncode != 0:
                print(f"{RED}❌ Staging all changes failed.{RESET}")
                sys.exit(res.returncode)
            break

        if choice == "p":
            res = run("git add -p")
            if res.returncode != 0:
                print(f"{RED}❌ Staging (patch) failed.{RESET}")
                sys.exit(res.returncode)
            break

        if choice == "f":
            selection = input("Enter file numbers (e.g. 1,3,4 or 1-5,7): ").strip()
            if not selection:
                print(f"{YELLOW}⚠️  No selection given. Nothing staged.{RESET}")
                sys.exit(0)

            picked = []
            parts = [p.strip() for p in selection.split(",") if p.strip()]
            for p in parts:
                if "-" in p:
                    a, b = p.split("-", 1)
                    try:
                        a_i = int(a)
                        b_i = int(b)
                    except ValueError:
                        continue
                    for idx in range(min(a_i, b_i), max(a_i, b_i) + 1):
                        if 1 <= idx <= len(files):
                            picked.append(files[idx - 1])
                else:
                    try:
                        idx = int(p)
                    except ValueError:
                        continue
                    if 1 <= idx <= len(files):
                        picked.append(files[idx - 1])

            picked = list(dict.fromkeys(picked))
            if not picked:
                print(f"{YELLOW}⚠️  No valid file numbers selected. Nothing staged.{RESET}")
                sys.exit(0)

            quoted = " ".join(shlex.quote(f) for f in picked)
            res = run(f"git add -- {quoted}")
            if res.returncode != 0:
                print(f"{RED}❌ Staging selected files failed.{RESET}")
                sys.exit(res.returncode)
            break

        print(f"{YELLOW}⚠️  Unknown choice '{choice}'. Try again.{RESET}\n")

    staged = run("git diff --cached --name-only", capture=True)
    if not (staged.stdout or "").strip():
        print(f"{YELLOW}⚠️  Nothing staged. Commit skipped.{RESET}")
        sys.exit(0)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-y",
        action="store_true",
        help="Auto mode: fetch, pull if behind, stage all, commit, push (no prompts)"
    )
    args = parser.parse_args()

    script_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
    os.chdir(script_dir)

    ensure_git_repo()

    # Always do fetch->pull-if-behind first (your requested behavior)
    pull_if_needed()

    # If no local changes, exit
    if not get_changed_files():
        print(f"{YELLOW}⚠️  No changes detected — commit skipped.{RESET}")
        return

    data = load_data()
    msg, today_str, day_number, work_day_number, commits_today_next = compute_commit_fields(data)
    msg_ref = {"msg": msg}

    print(f"\n{CYAN}📌 Commit preview:{RESET}")
    print(f'   "{msg_ref["msg"]}"\n')

    if args.y:
        # Auto mode: no prompts
        res = run("git add --all")
        if res.returncode != 0:
            print(f"{RED}❌ Staging failed.{RESET}")
            return

        # escape quotes just in case
        safe_msg = msg_ref["msg"].replace('"', '\\"')
        result = run(f'git commit -m "{safe_msg}"')
        if result.returncode != 0:
            print(f"{RED}❌ Commit failed.{RESET}")
            return

        # save counters only after successful commit
        data["daily_commits"][today_str] = commits_today_next
        save_data(data)

        print(f"{GREEN}⬆️  Pushing to remote...{RESET}")
        push = run("git push")
        if push.returncode != 0:
            print(f"{RED}❌ Push failed.{RESET}")
            return

        print(f"\n{GREEN}✅ Done!{RESET}")
        print(f"📆 Day: {day_number}")
        print(f"💼 Work Day: {work_day_number}")
        print(f"📊 Commits today: {commits_today_next}\n")
        return

    # Interactive mode: ONE prompt handles staging + edit message
    stage_menu_and_maybe_edit_msg(msg_ref)

    safe_msg = msg_ref["msg"].replace('"', '\\"')
    result = run(f'git commit -m "{safe_msg}"')
    if result.returncode != 0:
        print(f"{RED}❌ Commit failed.{RESET}")
        return

    # save counters only after successful commit
    data["daily_commits"][today_str] = commits_today_next
    save_data(data)

    print(f"{GREEN}⬆️  Pushing to remote...{RESET}")
    push = run("git push")
    if push.returncode != 0:
        print(f"{RED}❌ Push failed.{RESET}")
        return

    print(f"\n{GREEN}✅ Done!{RESET}")
    print(f"📆 Day: {day_number}")
    print(f"💼 Work Day: {work_day_number}")
    print(f"📊 Commits today: {commits_today_next}\n")

if __name__ == "__main__":
    main()