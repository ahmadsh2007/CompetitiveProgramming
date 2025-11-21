import sys

input = sys.stdin.read
data = input().strip().split()
t = int(data[0])
ptr = 1
out_lines = []

for _ in range(t):
    n = int(data[ptr]); ptr += 1
    X = int(data[ptr]); ptr += 1
    a = list(map(int, data[ptr:ptr+n])); ptr += n

    a.sort()
    i, j = 0, n - 1
    r = 0
    order = []
    bonus = 0

    while i <= j:
        gap = X - r if r != 0 else X
        if a[j] >= gap:
            order.append(a[j])
            bonus += a[j]
            r = (r + a[j]) % X
            j -= 1
        else:
            order.append(a[i])
            r += a[i]
            i += 1

    out_lines.append(str(bonus))
    out_lines.append(" ".join(map(str, order)))

print("\n".join(out_lines))
