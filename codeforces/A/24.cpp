/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<pair<int, pair<int, int>>>> adj;
vector<bool> vis;
int cur = 0;

void dfs(int u, int last) {
    vis[u] = 1;
    for (auto &v : adj[u]) {
        if (!vis[v.first]) {
            if (u == v.second.first) {
                cur += v.second.second;
            }
            dfs(v.first, u);
        }
        else if (v.first == 1 && v.first != last) {
            if (v.second.first == u) {
                cur += v.second.second;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, {});
    vis.assign(n + 1,  0);
    vis[1] = 1;
    cur = 0;
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        tot += w;
        adj[u].push_back({v, {u, w}});
        adj[v].push_back({u, {u, w}});
    }
    vis[1] = 1;
    if (adj[1][0].second.first == 1) cur += adj[1][0].second.second;
    dfs(adj[1][0].first, 1);
    cout << min(tot - cur, cur) << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}