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
    int n; cin >> n;
    
    vector<int> lg(n + 1);
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    vector<vector<int>> st(lg[n] + 1, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> st[0][i];
    }
    for (int p = 1; p <= lg[n]; ++p) {
        for (int i = 0; i + (1 << p) <= n; ++i) {
            st[p][i] = gcd(st[p - 1][i], st[p - 1][i + (1 << (p - 1))]);
        }
    }

    map<int, int> ans;
    for (int l = 0; l < n; ++l) {
        int i = l, g = 0;
        while (i < n) {
            g = gcd(g, st[0][i]);
            int j = i;
            for (int p = lg[n]; p >= 0; --p) {
                if (j + (1 << p) <= n and st[p][j] % g == 0) {
                    j += 1 << p;
                }
            }
            ans[g] += j - i;
            i = j;
        }
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << ans[x] << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}