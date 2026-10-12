#!/usr/bin/env python3
"""Codeforces contest-type analyzer. Stdlib only.

Data is fetched on the fly and kept in memory (no cache file).
1) Refresh  - fetch from Codeforces again (all contests), print the table
2) Custom   - keep only contests after a date (YYYY-MM-DD), print the table
3) Suggest  - recommendations from the current data
4) Print    - list every contest in the current data, then the table
"""
import json, os, sys, urllib.request, urllib.parse
from collections import defaultdict
from datetime import datetime, timezone

HANDLE = "Leeking"
SKIP_FIRST = 2          # ignore the first N contests (debut jumps)
TARGET = 1900           # Candidate Master


def api(method, **params):
    url = f"https://codeforces.com/api/{method}?" + urllib.parse.urlencode(params)
    with urllib.request.urlopen(url, timeout=30) as r:
        data = json.load(r)
    if data.get("status") != "OK":
        raise RuntimeError(data.get("comment", "API error"))
    return data["result"]


def division(name):
    n = name.lower()
    if "educational" in n:
        return "Edu"
    if "div. 1 + div. 2" in n or "div.1 + div.2" in n:
        return "Div1+2"
    if "global" in n:
        return "Global"
    for d in "1234":
        if f"div. {d}" in n:
            return "Div" + d
    return "Other"


def fetch():
    ratings = api("user.rating", handle=HANDLE)
    contests = {c["id"]: c for c in api("contest.list", gym="false")}
    rows = []
    for x in ratings[SKIP_FIRST:]:
        c = contests.get(x["contestId"], {})
        rows.append({
            "id": x["contestId"],
            "name": x["contestName"],
            "scoring": "Penalty" if c.get("type") == "ICPC" else "Points",
            "div": division(x["contestName"]),
            "hours": c.get("durationSeconds", 0) / 3600,
            "rank": x["rank"],
            "delta": x["newRating"] - x["oldRating"],
            "time": x["ratingUpdateTimeSeconds"],
        })
    out = {"handle": HANDLE, "rating": ratings[-1]["newRating"],
           "peak": max(x["newRating"] for x in ratings),
           "since": None, "rows": rows}
    return out


def fmt_hours(h):
    m = round(h * 60)
    return f"{m // 60}h{m % 60:02d}" if m % 60 else f"{m // 60}h"


def groups(rows):
    g = defaultdict(list)
    for r in rows:
        g[(r["scoring"], r["div"], r["hours"])].append(r["delta"])
    return g


def table(rows):
    g = groups(rows)
    print(f"\n{'Scoring':8} {'Type':8} {'Length':7} {'N':>3} {'Net':>6} {'Up/Down':>8} {'Avg':>7}")
    print("-" * 52)
    for (s, d, h), v in sorted(g.items()):
        up = sum(1 for a in v if a > 0)
        dn = sum(1 for a in v if a < 0)
        print(f"{s:8} {d:8} {fmt_hours(h):7} {len(v):>3} {sum(v):>+6} {f'{up}/{dn}':>8} {sum(v)/len(v):>+7.1f}")
    print(f"\n{len(rows)} contests, net {sum(r['delta'] for r in rows):+d}")


def suggest(data):
    rows = data["rows"]
    now = data["rating"]
    print(f"\nBased on current data ({'all contests' if not data.get('since') else 'since ' + data['since']})")
    print(f"{data['handle']}: rating {now}, peak {data['peak']}, "
          f"{TARGET - now:+d} to reach {TARGET}")
    g = [(k, v) for k, v in groups(rows).items() if len(v) >= 2]
    ranked = sorted(g, key=lambda kv: sum(kv[1]) / len(kv[1]), reverse=True)

    def line(kv):
        (s, d, h), v = kv
        return f"  {d} {fmt_hours(h)} ({s}): avg {sum(v)/len(v):+.1f} over {len(v)} contests"

    print("\nPrioritize (best average, 2+ contests):")
    top = [kv for kv in ranked[:3] if sum(kv[1]) > 0]
    for kv in top:
        print(line(kv))
    print("\nBe careful with (worst average):")
    for kv in ranked[-3:][::-1]:
        if sum(kv[1]) < 0 and kv not in top:
            print(line(kv))
    best = sum(ranked[0][1]) / len(ranked[0][1]) if ranked else 0
    if best > 0 and TARGET > now:
        print(f"\nAt the best-type average (+{best:.0f}) you need about "
              f"{-(-(TARGET - now) // round(best))} such contests - but learning topics "
              "(DP, DSU, combinatorics, ...) moves rating more than volume.")
    print("\nNote: Div3/Div4 stop being rated for you above 1600/1400, "
          "and Edu rounds use penalty + hacks.")


def custom(full):
    s = input("After which date? (YYYY-MM-DD): ").strip()
    try:
        ts = datetime.strptime(s, "%Y-%m-%d").replace(tzinfo=timezone.utc).timestamp()
    except ValueError:
        print("Bad date format.")
        return None
    rows = [r for r in full["rows"] if r["time"] >= ts]
    if not rows:
        print("No contests after that date.")
        return None
    data = dict(full, since=s, rows=rows)
    print(f"Filtered: contests since {s}")
    table(rows)
    return data


def show(data):
    since = data.get("since")
    print(f"\nData: {data['handle']}, {'all contests' if not since else 'since ' + since}")
    print(f"{'ID':>5}  {'Date':10}  {'Scoring':8} {'Type':7} {'Len':5} {'Rank':>6} {'Delta':>6}  Name")
    for r in data["rows"]:
        d = datetime.fromtimestamp(r["time"], timezone.utc).strftime("%Y-%m-%d")
        print(f"{r['id']:>5}  {d}  {r['scoring']:8} {r['div']:7} {fmt_hours(r['hours']):5} "
              f"{r['rank']:>6} {r['delta']:>+6}  {r['name'][:50]}")
    table(data["rows"])


def main():
    print("Fetching data...")
    full = fetch()
    data = full
    while True:
        print("\n[1] Refresh   [2] Custom (after date)   [3] Suggestions   [4] Print data   [q] Quit")
        c = input("> ").strip().lower()
        try:
            if c == "1":
                full = data = fetch()
                table(data["rows"])
            elif c == "2":
                data = custom(full) or data
            elif c == "3":
                suggest(data)
            elif c == "4":
                show(data)
            elif c in ("q", "quit", ""):
                return
        except Exception as e:
            print("Error:", e)


if __name__ == "__main__":
    main()
