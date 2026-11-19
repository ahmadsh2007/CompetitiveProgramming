/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python

const int INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, ell, k; cin >> n >> ell >> k;
    vector<int> d(n);
    for (auto &x : d) cin >> x;
    d.push_back(ell);
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    for (int i = 0; i <= k; ++i) {
        dp[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= k; ++j) {
            for (int k = i + 1; k <= min(i + 1 + j, n); ++k) {
                int rm = k - i - 1;
                int cost = a[i] * (d[k] - d[i]) + dp[k][j - rm];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][k] << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}