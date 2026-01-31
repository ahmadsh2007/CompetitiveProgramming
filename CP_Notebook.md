# Competitive Programming Notebook (C++) — Print Edition

**Author:** Ahmad Shatnawi  
**Goal:** fast reference during contests (clean + correct + print-friendly)

> Tip for printing: export this `.md` to PDF (VS Code / Typora / Obsidian / Pandoc). Page breaks are marked with `\pagebreak`.

## Contents
1. [Template](#template)
2. [Vectors, Iterators, Pairs](#vectors)
3. [Sorting & Comparators](#sorting)
4. [Binary Search & Bounds](#binary-search)
5. [Prefix Sums & partial_sum](#prefix)
6. [Frequency Counting (arrays/maps)](#freq)
7. [2D Prefix Sum](#prefix2d)
8. [Sets & Multisets](#sets)
9. [Stack, Queue, Deque, Priority Queue](#sqdpq)
10. [Strings quick reference](#strings)
11. [Structs + Sorting custom types](#structs)

\pagebreak
---

## Template
<a id="template"></a>

### Notes
- **Don’t** macro-rename `cin` / `cout` (it breaks compilation). Use `readv/printv` instead.
- `#define int long long` is common in CP. If you use it, be careful with:
  - `vector<int>` becomes `vector<long long>`
  - `INT_MAX` is still 2e9; use `LLONG_MAX`
- Prefer `\n` over `endl` for speed.

```cpp
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../Utils/debug.h"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string

using ll  = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
using i128  = __int128;

#define vi  vector<int>
#define vll vector<ll>

#define readv(v)  for (auto &x : (v)) cin >> x;
#define printv(v) for (auto &x : (v)) cout << x << ' ';

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void solve() {
    // TODO
}

const int TESTCASES = 1;

signed main() {
#ifndef ONLINE_JUDGE
#if __has_include("../../Utils/debug.h")
    freopen("../../Utils/input.txt", "r", stdin);
    freopen("../../Utils/output.txt", "w", stdout);
#else
    freopen("../../../Utils/input.txt", "r", stdin);
    freopen("../../../Utils/output.txt", "w", stdout);
#endif
#endif

    ull T = 1;
    if (TESTCASES == 1) cin >> T;
    else if (TESTCASES == 2) {
#ifndef ONLINE_JUDGE
        cin >> T;
#endif
    }

    while (T--) solve();
    return 0;
}
```
\pagebreak
---

## Vectors, Iterators, Pairs
<a id="vectors"></a>

### Vectors (the right way)
**Rule:** either you **pre-size** then assign by index, OR you start empty and `push_back`.

- ✅ Pre-sized:
  - `vector<int> v(n);` then `cin >> v[i]`
- ✅ Dynamic:
  - `vector<int> v;` then `v.push_back(x)`
- ❌ Don’t pre-size and also push_back in the same logic unless you mean to grow beyond `n`.

```cpp
int n; 
cin >> n;

// A) Pre-sized reading
vector<int> v(n);
for (auto &x : v) cin >> x;

// B) Dynamic reading
vector<int> w;
w.reserve(n);            // optional (performance)
for (int i = 0; i < n; i++) {
    int x; cin >> x;
    w.push_back(x);
}
```
### Iterators (pointer-like)
- `v.begin()` points to first element.
- `*(v.begin() + i)` is the element at index `i`.
- `v.end()` points **after** the last element.

```cpp
cout << *(v.begin() + 2) << '\n'; // element at index 2
```
### Pairs
- `pair<int,int> p = {a,b};`
- Access: `p.first`, `p.second`

```cpp
int a, b; 
cin >> a >> b;

pair<int,int> p1 = make_pair(a, b);
pair<int,int> p2 = {a, b};

cout << p2.first << ' ' << p2.second << '\n';

// Vector of pairs
vector<pair<int,int>> vp;
vp.push_back({a, b});
```
\pagebreak
---

## Sorting & Comparators
<a id="sorting"></a>

### Basics
- `sort(all(v))` → ascending
- `sort(rall(v))` → descending
- Sort first `k` elements: `sort(v.begin(), v.begin()+k)`
- Complexity: `O(n log n)`

```cpp
vector<int> v = {5, 2, 9, 1};
sort(all(v));      // 1 2 5 9
sort(rall(v));     // 9 5 2 1

int k = 2;
sort(v.begin(), v.begin() + k); // sorts only v[0..k-1]
```
### Sorting pairs
- Default: lexicographic `(first, then second)`.
- Custom: lambda comparator.

```cpp
vector<pair<int,int>> vp = {{3, 5}, {1, 7}, {2, 5}};

// Default: first then second
sort(all(vp));

// By second ascending
sort(all(vp), [](auto &p1, auto &p2){
    return p1.second < p2.second;
});

// By second desc, tie by first asc
sort(all(vp), [](auto &p1, auto &p2){
    if (p1.second != p2.second) return p1.second > p2.second;
    return p1.first < p2.first;
});
```
### Comparator rules (VERY IMPORTANT)
- Must return `true` if **a should come before b**.
- Must be **strict** (no `<=`), otherwise sort can break.
- For custom structs, prefer `operator<` or a lambda.

\pagebreak
---

## Binary Search & Bounds
<a id="binary-search"></a>

### On arrays/vectors (lower_bound / upper_bound)
Works on **sorted** containers.

- `lower_bound`: first position with `value >= x`
- `upper_bound`: first position with `value > x`
- Index: `it - v.begin()`

```cpp
vector<int> a = {1, 2, 2, 5, 9}; // sorted
int x = 2;

int i1 = lower_bound(all(a), x) - a.begin(); // points to first 2 (index 1)
int i2 = upper_bound(all(a), x) - a.begin(); // points to first >2 (index 3)

int count_x = i2 - i1; // occurrences of x in sorted array
```
### On sets/multisets
- Use member functions: `s.lower_bound(x)` / `s.upper_bound(x)`.
- They return iterators; check `it != s.end()` before dereferencing.

```cpp
set<int> s = {1, 3, 7};
int x = 4;

auto it = s.lower_bound(x); // first element >= 4
if (it != s.end()) cout << *it << '\n';
```
### Binary search on the answer (predicate)
Use when you search for **minimum/maximum valid value**.

```cpp
// Find smallest mid such that ok(mid) == true
long long lo = 0, hi = 1e18; // adjust
auto ok = [&](long long mid) -> bool {
    // predicate here
    return mid * mid >= 100; // example
};

while (lo < hi) {
    long long mid = lo + (hi - lo) / 2;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
}
// lo is answer
```
\pagebreak
---

## Prefix Sums & partial_sum
<a id="prefix"></a>

### 1D Prefix Sum (range sum in O(1))
- Build `pref` of size `n+1`
- `pref[i]` = sum of first `i` elements (`a[0..i-1]`)
- Range sum `[l, r]` (0-indexed, inclusive): `pref[r+1] - pref[l]`

```cpp
int n; cin >> n;
vector<long long> a(n);
for (auto &x : a) cin >> x;

vector<long long> pref(n + 1, 0);
for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];

// sum of a[l..r], 0-indexed inclusive
int l, r; cin >> l >> r;
long long ans = pref[r + 1] - pref[l];
cout << ans << '\n';
```
### accumulate (reduce)
- Default is sum.
- You can pass a custom binary operation.

```cpp
vector<long long> a = {5, 10, 15};

long long sum = accumulate(all(a), 0LL); // 30

auto mul = [](long long x, long long y){ return x * y; };
long long prod = accumulate(all(a), 1LL, mul); // 750
```
### partial_sum (build prefix using an operation)
- Default: prefix sums.
- Can do prefix products / max / etc.

```cpp
vector<long long> b = {5, 10, 15};
vector<long long> prefSum(b.size());
partial_sum(all(b), prefSum.begin()); // 5 15 30

auto mul = [](long long x, long long y){ return x * y; };
vector<long long> prefProd(b.size());
partial_sum(all(b), prefProd.begin(), mul); // 5 50 750
```
\pagebreak
---

## Frequency Counting (arrays / maps)
<a id="freq"></a>

### Frequency array (fastest)
Use when values are in a small range.

- Integers in `[0..MAX]` → `vector<int> freq(MAX+1)`
- Lowercase letters → `freq[s[i]-'a']`
- Uppercase letters → `freq[s[i]-'A']`
- Digits → `freq[s[i]-'0']`

```cpp
// integers
int MAXV = 100000;
vector<int> freq(MAXV + 1, 0);
for (int x : a) freq[x]++;

// lowercase letters
string s; cin >> s;
vector<int> f(26, 0);
for (char c : s) f[c - 'a']++;
```
### map / unordered_map (flexible)
- `map`: sorted keys, `O(log n)`.
- `unordered_map`: average `O(1)`.

```cpp
map<int,int> mp;
mp[5] = 7;
mp[8] = 0;

for (auto [k, v] : mp) cout << k << ' ' << v << '\n';

mp.erase(5);
cout << mp.size() << '\n';
cout << mp.empty() << '\n';
```
\pagebreak
---

## 2D Prefix Sum
<a id="prefix2d"></a>

### Idea
For grid `a` (1-indexed), build `pref` where:
`pref[i][j]` = sum of rectangle `(1,1) .. (i,j)`.

Rectangle sum `(r1,c1) .. (r2,c2)`:
`pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1]`

```cpp
int n, m; cin >> n >> m;
vector<vector<long long>> a(n + 1, vector<long long>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> a[i][j];

vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        pref[i][j] = a[i][j]
                   + pref[i-1][j]
                   + pref[i][j-1]
                   - pref[i-1][j-1];
    }
}

int r1, c1, r2, c2; // 1-indexed
cin >> r1 >> c1 >> r2 >> c2;
long long ans = pref[r2][c2]
              - pref[r1-1][c2]
              - pref[r2][c1-1]
              + pref[r1-1][c1-1];
cout << ans << '\n';
```
\pagebreak
---

## Sets & Multisets
<a id="sets"></a>

### What you get
- `set`: sorted, **unique**, `O(log n)` insert/erase/find
- `multiset`: sorted, **duplicates allowed**
- No random access (`s[i]` doesn’t exist)

```cpp
vector<int> v = {2, 3, 2, 5, 2, 7, 1, 1, 3};

set<int> s(v.begin(), v.end());            // {1,2,3,5,7}
set<int, greater<int>> sd(v.begin(), v.end()); // descending order

// iterating
for (int x : s) cout << x << ' ';
cout << '\n';

int X = 3;

// find / erase
auto it = s.find(X);
if (it != s.end()) s.erase(it);

// lower_bound / upper_bound
it = s.lower_bound(X); // >= X
```
### multiset differences
- `ms.erase(X)` removes **all** copies.
- To remove one copy: `ms.erase(ms.find(X))` (after checking it exists).

```cpp
multiset<int> ms = {1, 1, 2, 2, 2, 5};

int X = 2;
cout << ms.count(X) << '\n'; // 3

// remove ONE copy
auto it = ms.find(X);
if (it != ms.end()) ms.erase(it);

// remove ALL copies
ms.erase(X);
```
\pagebreak
---

## Stack, Queue, Deque, Priority Queue
<a id="sqdpq"></a>

### Stack (LIFO)
- `push`, `pop`, `top`, `empty`

```cpp
stack<int> st;
st.push(5);
st.push(4);
cout << st.top() << '\n'; // 4
st.pop();
```
### Queue (FIFO)
- `push`, `pop`, `front`, `back`, `empty`

```cpp
queue<int> q;
q.push(5);
q.push(4);
cout << q.front() << ' ' << q.back() << '\n'; // 5 4
q.pop(); // removes 5
```
### Deque (double-ended)
- `push_front/back`, `pop_front/back`, `front`, `back`

```cpp
deque<int> dq;
dq.push_back(2);
dq.push_front(1); // 1 2
dq.push_back(3);  // 1 2 3
cout << dq.front() << ' ' << dq.back() << '\n';
```
### Priority queue (heap)
- Default: max-heap.
- Min-heap: `priority_queue<int, vector<int>, greater<int>>`

```cpp
priority_queue<int> mx; // max-heap
mx.push(9); mx.push(6); mx.push(8);
cout << mx.top() << '\n'; // 9

priority_queue<int, vector<int>, greater<int>> mn; // min-heap
mn.push(9); mn.push(6); mn.push(8);
cout << mn.top() << '\n'; // 6
```
### Typical complexities
- stack/queue/deque operations: `O(1)`
- priority_queue push/pop: `O(log n)`

\pagebreak
---

## Strings quick reference
<a id="strings"></a>

### Common operations
- `size()` / `length()`
- `find(substr)` → index or `string::npos`
- `substr(pos, len)`
- `push_back`, `pop_back`
- `insert`, `replace`
- `getline(cin, s)` for full line
- `toupper/tolower` (cast to unsigned char if you’re being pedantic)

```cpp
string s = "Ahmad Shatnawi";

cout << s.size() << '\n';

size_t pos = s.find("Ahmad");
if (pos != string::npos) cout << pos << '\n';

string sub = s.substr(0, 5); // "Ahmad"

s.push_back('!');
s.pop_back();

s.insert(0, "Mr. ");           // add prefix
s.replace(0, 3, "Dr.");        // replace range

string line;
getline(cin, line);

string a = "Ahmad", b = "Hamza";
a.swap(b);

sort(all(a));
reverse(all(a));
```
\pagebreak
---

## Structs + Sorting custom types
<a id="structs"></a>

### Struct + comparator
- Easiest: lambda in `sort`.
- Or define `operator<`.

```cpp
struct Star {
    int x, y, z;
};

int main() {
    const int N = 6;
    vector<Star> a(N);

    for (auto &s : a) cin >> s.x >> s.y >> s.z;

    // sort by x ascending
    sort(all(a), [](const Star& A, const Star& B){
        return A.x < B.x;
    });

    // sort by x descending
    sort(all(a), [](const Star& A, const Star& B){
        return A.x > B.x;
    });

    for (auto &s : a)
        cout << s.x << ' ' << s.y << ' ' << s.z << '\n';
}
```
---

## Small cleanup notes (from your original snippets)
- `sort(v.begin(), v.end() + 2)` is **wrong** — it must be `v.begin() + 2`.
- If `pref` is size `n+1`, then range sum is `pref[r+1] - pref[l]`.
- In 2D prefix, don’t reuse the raw input array name for prefix unless you’re sure.
- In prefix max/min, start from `i=0` carefully (no `prefix[-1]`).


### About your uploads
Some earlier uploaded files can expire in this chat. This print edition was rebuilt from the files that are still available in this session. If you had extra snippets that aren’t included, re-upload them and I’ll merge them in.
