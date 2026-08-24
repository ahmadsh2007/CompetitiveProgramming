#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define str string

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<int>> dp(5002, vector<int>(5002));
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = i; j <= n; ++j) {
            cur ^= a[j];
            dp[i][j] = cur;
        }
    }

    for (int k = 2; k <= n; ++k) {
        for (int i = 1; i + k - 1 <= n; ++i) {
            int j = i - 1 + k;
            dp[i][j] = max({dp[i][j], dp[i + 1][j], dp[i][j - 1]});
        }
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
    
        cout << dp[l][r] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}