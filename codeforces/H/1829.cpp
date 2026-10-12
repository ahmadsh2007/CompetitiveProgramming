/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define str string // What a Python

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> dp(n, vector<int>(64));
    for (int i = 0; i < n; ++i) {
        if (i) {
            for (int j = 0; j < 64; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                dp[i][(j & a[i])] = (dp[i][(j & a[i])] + dp[i - 1][j]) % MOD;
            }
        }
        dp[i][a[i]] = (dp[i][a[i]] + 1) % MOD;
    }

    int ans = 0;
    for (int j = 0; j < 64; ++j) {
        if (__builtin_popcount(j) != k) continue;
        ans = (ans + dp[n - 1][j]) % MOD;
    }

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