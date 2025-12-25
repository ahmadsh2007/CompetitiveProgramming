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
#define str string // What a Python

#define _vi1(a) vector<int> a;
#define _vi2(a,n) vector<int> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vi(...) GET_MACRO(__VA_ARGS__, _vi2, _vi1)(__VA_ARGS__)
#define read(v) for (auto &x : v) cin >> x;

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using ull = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, k; cin >> n >> k;
    vi(a, n) read(a)
    sort(all(a));
    vi(pre, n + 1);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i] + a[i];

    // 3 4
    // 3 5
    // 4 2
    // 3 4

    // int l = 1, r = 1, ans = -1, ansNum;
    // while (r <= n) {
    //     int total = pre[r - 1] - pre[l - 1];
    //     if ((r - l) * a[r] - total <= k) ansNum = a[r], ans = r + 1 - l, r++;
    //     else l++;
    // }

    int l = 1, ans = 1, ansNum = a[0];
    for (int r = 2; r <= n; r++) {
        while (((r - l) * a[r - 1]) - (pre[r - 1] - pre[l - 1]) > k) l++;
        if (ans < r + 1 - l) ans = r + 1 - l, ansNum = a[r - 1];
    }

    cout << ans << ' ' << ansNum;
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}