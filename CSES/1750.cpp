/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int LOG = 30;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> lca(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> lca[0][i];
    }
    for (int i = 1; i < LOG; ++i) {
        for (int j = 1; j <= n; ++j) {
            lca[i][j] = lca[i - 1][lca[i - 1][j]];
        }
    }
    while (q--) {
        int x, k; cin >> x >> k;
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                x = lca[i][x];
            }
        }
        cout << x << endl;
    }
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}