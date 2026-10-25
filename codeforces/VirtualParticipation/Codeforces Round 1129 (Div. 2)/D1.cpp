/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int mod = 998244353;

void solve() {
    int l, r; cin >> l >> r;
    int ans = 0;

    auto cost = [&](int n) {
        int s = 2 * n;
        for (int i = 0; i < 62; ++i) {
            if ((n >> i) & 1) {
                s += i;
            }
        }
        return s;
    };
    auto f = [&](int N) -> int {
        if (N == 0) {
            return 0;
        }
        int T = N / 2, l = 1, r = 2 * T + 70;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m - __builtin_popcountll(m) >= T) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        int n = l, best = cost(n);
        for (int k = 0; k <= 60; ++k) {
            if (!((n >> k) & 1)) {
                best = min(best, cost(((n >> k) | 1ll) << k));
            }
        }
        return best - N;
    };
    for (int n = l; n <= r; ++n)
        ans = (ans + f(n) % mod) % mod;
    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}