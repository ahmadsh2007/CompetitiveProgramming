/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dp[1001][1001][2];
int n, k;

int solve(int n, int k, int d) {
    if (k == 1) return 1;
    if (dp[n][k][d] != -1) return dp[n][k][d];

    int val = 2;
    if (d == 1) {
        if (n > 1) val += solve(n - 1, k - 1, 1 - d) - 1;
        val %= MOD;
        if (n < ::n) val += solve(n + 1, k, d) - 1;
        val %= MOD;
        dp[n][k][d] = val;
    }
    else {
        if (n < ::n) val += solve(n + 1, k - 1, 1 - d) - 1;
        val %= MOD;
        if (n > 1) val += solve(n - 1, k, d) - 1;
        val %= MOD;
        dp[n][k][d] = val;
    }

    return val;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < 1001; ++i)
        for (int j = 0; j < 1001; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = -1;
    cout << solve(1, k, 1) << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1; cin >> TTT;
    while (TTT--) solve();
    return 0;
}