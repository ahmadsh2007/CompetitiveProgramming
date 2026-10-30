/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> c(n, vector<int>(k));
    map<vector<int>, int> m;
    for (auto &r : c) {
        for (auto &x : r) {
            cin >> x;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            vector<int> comp(k);
            for (int l = 0; l < k; ++l) {
                if (c[i][l] == c[j][l]) {
                    comp[l] = c[i][l];
                }
                else {
                    comp[l] = 3 - (c[i][l] + c[j][l]);
                }
            }
            m[comp]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = m[c[i]];
        cerr << cnt << endl;
        ans += cnt * (cnt - 1) / 2;
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