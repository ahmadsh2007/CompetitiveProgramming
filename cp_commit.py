import os
import sys
import subprocess
import json
from datetime import datetime

COUNTER_FILE = ".cp_counter"

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

def main():
    # Always operate from script directory
    script_dir = os.path.dirname(os.path.abspath(sys.argv[0]))
    os.chdir(script_dir)

    data = load_data()

    start_date = datetime.strptime(data["start_date"], "%Y-%m-%d").date()
    today = datetime.today().date()

    # Count total days since starting
    day_number = (today - start_date).days + 1

    today_str = today.strftime("%Y-%m-%d")

    # Work day logic
    if today_str not in data["work_days"]:
        data["work_days"].append(today_str)
        data["work_days"].sort()

    work_day_number = data["work_days"].index(today_str) + 1

    # Commit logic per work day
    commits_today = data["daily_commits"].get(today_str, 0) + 1

    # Format
    msg = f"Day {day_number:03d} Work Day {work_day_number:03d} Commit {commits_today:02d}"

    print("\n📌 Commit preview:")
    print(f"   \"{msg}\"\n")

    confirm = input("Proceed with commit? (y/n): ").lower()
    if confirm != 'y':
        print("🚫 Cancelled.")
        return

    data["daily_commits"][today_str] = commits_today
    save_data(data)

    subprocess.run("git add --all", shell=True)
    result = subprocess.run(f'git commit -m "{msg}"', shell=True)

    if result.returncode != 0:
        print("❌ Commit failed.")
        return

    subprocess.run("git pull --rebase", shell=True)
    subprocess.run("git push", shell=True)

    print("\n✅ Done!")
    print(f"📆 Day: {day_number}")
    print(f"💼 Work Day: {work_day_number}")
    print(f"📊 Commits today: {commits_today}")

if __name__ == "__main__":
    main()
