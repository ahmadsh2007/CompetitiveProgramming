/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    s = ' ' + s;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<int> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        adj[p[i]] = i;
    }

    vector<bool> vis(n + 1);
    str cyc;
    auto dfs = [&](this auto&& self, int u) -> void {
        vis[u] = true;
        cyc += s[u];
        if (!vis[adj[u]]) {
            self(adj[u]);
        }
    };

    vector<int> vals;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            cyc.clear();
            dfs(i);
            for (int k = 1; k <= (int) cyc.size(); ++k) {
                if ((int) cyc.size() % k == 0 and cyc.substr(k) + cyc.substr(0, k) == cyc) {
                    vals.push_back(k);
                    break;
                }
            }
        }
    }

    int ans = 1;
    for (int i = 0; i < (int) vals.size(); ++i) {
        ans = lcm(ans, vals[i]);
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    cin >> TTT;
    while (TTT--) solve();
    return 0;
}