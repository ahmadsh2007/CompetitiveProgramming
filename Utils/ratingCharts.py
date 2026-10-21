lazy import json
lazy import urllib.request
lazy import urllib.error
lazy import numpy as np
lazy import matplotlib.pyplot as plt
lazy import matplotlib.gridspec as gridspec


# ---------- Codeforces API ----------
def fetch_contests(handle):
    url = f"https://codeforces.com/api/user.rating?handle={handle}"
    try:
        with urllib.request.urlopen(url, timeout=15) as resp:
            result = json.load(resp)
    except urllib.error.HTTPError as e:
        # Codeforces answers 400 with a JSON comment for unknown handles
        result = json.load(e)
    except urllib.error.URLError as e:
        raise SystemExit(f"Could not reach Codeforces: {e.reason}")

    if result.get("status") != "OK":
        raise SystemExit(f"Codeforces error: {result.get('comment', 'unknown')}")
    if not result["result"]:
        raise SystemExit(f"{handle} has no rated contests yet.")
    return result["result"]


# ---------- Input ----------
handle = input("Codeforces handle: ").strip()
contests_raw = fetch_contests(handle)
total = len(contests_raw)
print(f"Found {total} rated contests for {handle}.")

while True:
    skip = input(f"How many of the first contests to ignore? (0-{total - 1}): ").strip()
    if skip.isdigit() and 0 <= int(skip) < total:
        skip = int(skip)
        break
    print("Please enter a valid number.")

used = contests_raw[skip:]
order = np.array([c["newRating"] - c["oldRating"] for c in used])  # oldest -> newest
data = np.array(sorted(order))
n = len(data)
contests = np.arange(skip + 1, skip + n + 1)   # keep real contest numbers

# ---------- Statistics ----------
q1, median, q3 = np.percentile(data, [25, 50, 75])
iqr = q3 - q1
mean, std = data.mean(), data.std(ddof=1)
low_fence, high_fence = q1 - 1.5 * iqr, q3 + 1.5 * iqr
is_out = (data < low_fence) | (data > high_fence)
outliers = data[is_out]
gains, losses, zeros = (data > 0).sum(), (data < 0).sum(), (data == 0).sum()
window = min(5, n)
rolling = np.convolve(order, np.ones(window) / window, mode="valid")
cumulative = np.cumsum(order)


def longest_streak(arr, cond):
    best = cur = 0
    for x in arr:
        cur = cur + 1 if cond(x) else 0
        best = max(best, cur)
    return best


def avg(arr):
    return f"{arr.mean():+.1f}" if len(arr) else "—"


stats = [
    ("Contests used", f"{n}  (skipped {skip})"),
    ("Net change", f"{data.sum():+d}"),
    ("Mean", f"{mean:+.1f}"),
    ("Median", f"{median:+.1f}"),
    ("Std deviation", f"{std:.1f}" if n > 1 else "—"),
    ("Min / Max", f"{data.min():+d} / {data.max():+d}"),
    ("Q1 / Q3", f"{q1:+.1f} / {q3:+.1f}"),
    ("IQR", f"{iqr:.1f}"),
    ("Win rate", f"{gains / n:.0%}"),
    ("Avg gain", avg(data[data > 0])),
    ("Avg loss", avg(data[data < 0])),
    ("Longest win streak", f"{longest_streak(order, lambda x: x > 0)}"),
    ("Longest loss streak", f"{longest_streak(order, lambda x: x < 0)}"),
    ("Peak total change", f"{cumulative.max():+d}  (#{contests[cumulative.argmax()]})"),
    ("Lowest total change", f"{cumulative.min():+d}  (#{contests[cumulative.argmin()]})"),
    ("Outliers", ", ".join(f"{x:+d}" for x in outliers) or "None"),
]

# ---------- Style ----------
GREEN, RED, BLUE, GOLD, GRAY = "#16a34a", "#dc2626", "#2563eb", "#f59e0b", "#94a3b8"
TEXT, MUTED, BG, PANEL = "#0f172a", "#64748b", "#f8fafc", "#ffffff"

plt.rcParams.update({
    "font.family": "DejaVu Sans",
    "axes.facecolor": PANEL,
    "axes.edgecolor": "#e2e8f0",
    "axes.titleweight": "bold",
    "axes.titlesize": 11,
    "font.size": 9,
    "axes.titlelocation": "left",
    "axes.titlepad": 10,
    "axes.labelcolor": MUTED,
    "xtick.color": MUTED,
    "ytick.color": MUTED,
    "axes.spines.top": False,
    "axes.spines.right": False,
    "grid.color": "#e2e8f0",
})

fig = plt.figure(figsize=(14.5, 8.2), facecolor=BG)
gs = gridspec.GridSpec(2, 4, figure=fig, width_ratios=[1, 1.15, 0.9, 1.1],
                       hspace=0.42, wspace=0.35,
                       left=0.06, right=0.98, top=0.85, bottom=0.08)

fig.text(0.05, 0.95, f"{handle} — Codeforces Rating Change", fontsize=18,
         fontweight="bold", color=TEXT)
fig.text(0.05, 0.915,
         f"Contests {contests[0]}–{contests[-1]} of {total}  •  net {data.sum():+d}  •  "
         f"{gains} gains, {losses} losses, {zeros} unchanged",
         fontsize=10.5, color=MUTED)

# ---------- 1. Box plot + points ----------
ax = fig.add_subplot(gs[0, 0])
ax.boxplot(data, widths=0.5, patch_artist=True, showfliers=False,
           boxprops=dict(facecolor=BLUE + "22", edgecolor=BLUE, linewidth=1.8),
           medianprops=dict(color=GOLD, linewidth=2.5),
           whiskerprops=dict(color=BLUE, linewidth=1.5),
           capprops=dict(color=BLUE, linewidth=1.5))
rng = np.random.default_rng(1)
jit = 1 + rng.uniform(-0.12, 0.12, n)
ax.scatter(jit[~is_out], data[~is_out], s=22, alpha=0.7, zorder=3,
           c=np.where(data[~is_out] >= 0, GREEN, RED))
ax.scatter(jit[is_out], data[is_out], s=70, marker="D", zorder=4,
           c=np.where(data[is_out] >= 0, GREEN, RED), edgecolors="black")
for x, y in zip(jit[is_out], data[is_out]):
    ax.annotate(f"{y:+d}", (x, y), xytext=(10, 0), textcoords="offset points",
                va="center", fontsize=9, color=TEXT)
for y, lbl in [(q1, "Q1"), (median, "Median"), (q3, "Q3")]:
    ax.text(1.32, y, f"{lbl} {y:+.0f}", va="center", fontsize=9,
            color=GOLD if lbl == "Median" else BLUE, fontweight="bold")
ax.axhline(0, color=GRAY, linestyle="--", linewidth=1)
ax.set_xlim(0.6, 1.6)
ax.set_xticks([])
ax.set_ylabel("Rating change")
ax.set_title("Distribution (Box Plot)")
ax.grid(axis="y")

# ---------- 2. Change per contest + rolling average ----------
ax = fig.add_subplot(gs[0, 1:3])
ax.bar(contests, order, color=np.where(order >= 0, GREEN, RED), alpha=0.85)
ax.plot(contests[window - 1:], rolling, color=TEXT, linewidth=2,
        label=f"{window}-contest average")
best, worst = order.argmax(), order.argmin()
for idx, label in [(best, "Best"), (worst, "Worst")]:
    left_half = idx < n / 2
    ax.annotate(f"{label} {order[idx]:+d}", (contests[idx], order[idx]),
                xytext=(18 if left_half else -18, 0),
                textcoords="offset points", fontsize=9, va="center",
                ha="left" if left_half else "right",
                bbox=dict(boxstyle="round,pad=0.25", fc=PANEL, ec="#e2e8f0"),
                arrowprops=dict(arrowstyle="->", color=MUTED))
ax.margins(y=0.12)
ax.axhline(0, color=TEXT, linewidth=0.8)
ax.set_xlabel("Contest #")
ax.set_ylabel("Rating change")
ax.set_title("Change per Contest")
ax.legend(frameon=False, loc="lower right", bbox_to_anchor=(1, 1.0),
          borderaxespad=0.3)
ax.grid(axis="y")

# ---------- 3. Stats table ----------
ax = fig.add_subplot(gs[:, 3])
ax.axis("off")
ax.set_title("Summary Statistics")
table = ax.table(cellText=stats, colLabels=["Statistic", "Value"],
                 cellLoc="left", colLoc="left", bbox=[0, 0.02, 1, 0.96])
table.auto_set_font_size(False)
table.set_fontsize(9)
for (r, c), cell in table.get_celld().items():
    cell.set_edgecolor("#e2e8f0")
    if r == 0:
        cell.set_facecolor(BLUE)
        cell.set_text_props(color="white", weight="bold")
    else:
        cell.set_facecolor("#f1f5f9" if r % 2 else PANEL)
        if c == 1:
            cell.set_text_props(weight="bold", color=TEXT)
            txt = cell.get_text().get_text()
            mixed = "/" in txt or "," in txt
            if not mixed and txt.startswith("+"):
                cell.get_text().set_color(GREEN)
            elif not mixed and txt.startswith("-"):
                cell.get_text().set_color(RED)

# ---------- 4. Histogram ----------
ax = fig.add_subplot(gs[1, 0])
step = 25
bins = np.arange(np.floor(data.min() / step) * step,
                 np.ceil(data.max() / step) * step + step + 1, step)
_, edges, patches = ax.hist(data, bins=bins, edgecolor="white", linewidth=1)
for p, left in zip(patches, edges[:-1]):
    p.set_facecolor(GREEN if left >= 0 else RED)
    p.set_alpha(0.8)
ax.axvline(median, color=GOLD, linewidth=2, label=f"Median {median:+.1f}")
ax.axvline(mean, color=TEXT, linestyle="--", linewidth=1.5,
           label=f"Mean {mean:+.1f}")
ax.set_xlabel("Rating change")
ax.set_ylabel("Contests")
ax.set_title("Histogram")
ax.legend(frameon=False)
ax.grid(axis="y")

# ---------- 5. Cumulative change ----------
ax = fig.add_subplot(gs[1, 1])
ax.plot(contests, cumulative, color=BLUE, linewidth=2.2, marker="o", markersize=3)
ax.fill_between(contests, cumulative, 0, where=cumulative >= 0,
                color=GREEN, alpha=0.15, interpolate=True)
ax.fill_between(contests, cumulative, 0, where=cumulative < 0,
                color=RED, alpha=0.15, interpolate=True)
for idx, label, color in [(cumulative.argmax(), "Peak", GREEN),
                          (cumulative.argmin(), "Low", RED)]:
    left_half = idx < n / 2
    ax.scatter(contests[idx], cumulative[idx], color=color, s=60, zorder=3,
               edgecolors=TEXT)
    ax.annotate(f"{label} {cumulative[idx]:+d}", (contests[idx], cumulative[idx]),
                xytext=(10 if left_half else -10, 8), textcoords="offset points",
                ha="left" if left_half else "right", fontsize=9, fontweight="bold")
ax.axhline(0, color=TEXT, linewidth=0.8)
ax.margins(y=0.12)
ax.set_xlabel("Contest #")
ax.set_ylabel("Total change")
ax.set_title("Cumulative Rating Change")
ax.grid(alpha=0.5)
# ---------- 6. Gains vs losses ----------
ax = fig.add_subplot(gs[1, 2])
counts = [(gains, f"Gains ({gains})", GREEN),
          (losses, f"Losses ({losses})", RED),
          (zeros, f"No change ({zeros})", "#d1d5db")]
counts = [c for c in counts if c[0] > 0]
ax.pie([c[0] for c in counts], labels=[c[1] for c in counts],
       colors=[c[2] for c in counts], autopct="%1.0f%%", startangle=90,
       pctdistance=0.7, labeldistance=1.12,
       wedgeprops=dict(edgecolor="white", linewidth=1.5),
       textprops=dict(fontsize=9, color=TEXT))
ax.set_title("Gains vs Losses")

plt.savefig(f"{handle}_rating.png", dpi=150, facecolor=BG)
plt.show()

# ---------- Terminal table ----------
print(f"\n{'Statistic':<22}Value")
print("-" * 40)
for name, value in stats:
    print(f"{name:<22}{value}")