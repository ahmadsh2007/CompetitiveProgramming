import os
import sys
import subprocess
import json
import shlex
from datetime import datetime

COUNTER_FILE = ".cp_counter"

RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
CYAN = "\033[36m"
RESET = "\033[0m"

def run(cmd, check=False, capture=False):
    """
    Helper to run shell commands.
    """
    return subprocess.run(
        cmd,
        shell=True,
        text=True,
        capture_output=capture,
        check=check
    )

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
    # Porcelain format: XY <path>
    res = run("git status --porcelain", capture=True)
    lines = [ln for ln in (res.stdout or "").splitlines() if ln.strip()]
    files = []
    for ln in lines:
        # handle rename format: "R  old -> new"
        # simplest: take text after first 3 chars, then if '->' take right side
        path_part = ln[3:].strip()
        if " -> " in path_part:
            path_part = path_part.split(" -> ", 1)[1].strip()
        files.append(path_part)
    return files


def ensure_git_repo():
    res = run("git rev-parse --is-inside-work-tree", capture=True)
    if res.returncode != 0 or (res.stdout or "").strip() != "true":
        print(f"{RED}❌ Not inside a Git repository.{RESET}")
        sys.exit(1)


def pull_rebase_autostash():
    print(f"{CYAN}🔄 Pulling latest changes (rebase + autostash)...{RESET}")
    # --autostash stashes local changes, rebases, then reapplies them
    res = run("git pull --rebase --autostash")
    if res.returncode != 0:
        print(f"{RED}❌ Pull/rebase failed (likely conflicts). Resolve them, then run again.{RESET}")
        print(f"{YELLOW}Tip:{RESET} Check 'git status' and follow Git’s conflict instructions.")
        sys.exit(res.returncode)


def stage_changes():
    files = get_changed_files()
    if not files:
        print(f"{YELLOW}⚠️  No changes detected — commit skipped.{RESET}")
        sys.exit(0)

    print(f"{CYAN}🧾 Changes detected:{RESET}")
    for i, f in enumerate(files, 1):
        print(f"  {i:>2}. {f}")

    print("\nStage options:")
    print("  [Enter] Stage all changes")
    print("  [p]     Patch mode (pick hunks)  -> git add -p")
    print("  [f]     Choose files to stage")
    choice = input("Choose staging mode: ").strip().lower()

    if choice == "p":
        res = run("git add -p")
        if res.returncode != 0:
            print(f"{RED}❌ Staging (patch) failed.{RESET}")
            sys.exit(res.returncode)
    elif choice == "f":
        selection = input("Enter file numbers to stage (e.g. 1,3,4 or 1-5,7): ").strip()
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

        picked = list(dict.fromkeys(picked))  # dedupe, keep order
        if not picked:
            print(f"{YELLOW}⚠️  No valid file numbers selected. Nothing staged.{RESET}")
            sys.exit(0)

        # Stage only selected files
        quoted = " ".join(shlex.quote(f) for f in picked)
        res = run(f"git add -- {quoted}")
        if res.returncode != 0:
            print(f"{RED}❌ Staging selected files failed.{RESET}")
            sys.exit(res.returncode)
    else:
        # Default: stage all
        res = run("git add --all")
        if res.returncode != 0:
            print(f"{RED}❌ Staging all changes failed.{RESET}")
            sys.exit(res.returncode)

    # Ensure something is staged
    staged = run("git diff --cached --name-only", capture=True)
    if not (staged.stdout or "").strip():
        print(f"{YELLOW}⚠️  Nothing staged. Commit skipped.{RESET}")
        sys.exit(0)

def main():
    script_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
    os.chdir(script_dir)

    ensure_git_repo()

    # 1) Pull first (and keep going) — handles remote updates in same run
    pull_rebase_autostash()

    data = load_data()

    # If after pulling, there are no local changes, exit
    if not get_changed_files():
        print(f"{YELLOW}⚠️  No changes detected — commit skipped.{RESET}")
        return

    start_date = datetime.strptime(data["start_date"], "%Y-%m-%d").date()
    today = datetime.today().date()

    day_number = (today - start_date).days + 1
    today_str = today.strftime("%Y-%m-%d")

    if today_str not in data["work_days"]:
        data["work_days"].append(today_str)
        data["work_days"].sort()

    work_day_number = data["work_days"].index(today_str) + 1

    commits_today = data["daily_commits"].get(today_str, 0) + 1
    msg = f"Day {day_number:03d} Work Day {work_day_number:03d} Commit {commits_today:02d}"

    print(f"\n{CYAN}📌 Commit preview:{RESET}")
    print(f"   \"{msg}\"\n")

    confirm = input("Press [e] to edit commit message, or Enter to continue: ").strip().lower()

    # 2) Option to edit what to push: staging choices
    stage_changes()

    # Commit
    if confirm == 'e':
        result = run(f'git commit -e -m "{msg}"')
    else:
        result = run(f'git commit -m "{msg}"')

    if result.returncode != 0:
        print(f"{RED}❌ Commit failed.{RESET}")
        return

    # Update counters ONLY after successful commit
    data["daily_commits"][today_str] = commits_today
    save_data(data)

    print(f"{GREEN}⬆️  Pushing to remote...{RESET}")
    push = run("git push")
    if push.returncode != 0:
        print(f"{RED}❌ Push failed.{RESET}")
        print(f"{YELLOW}Tip:{RESET} If remote changed again, run this script again or resolve any hints from Git.")
        return

    print(f"\n{GREEN}✅ Done!{RESET}")
    print(f"📆 Day: {day_number}")
    print(f"💼 Work Day: {work_day_number}")
    print(f"📊 Commits today: {commits_today}\n")

if __name__ == "__main__":
    main()