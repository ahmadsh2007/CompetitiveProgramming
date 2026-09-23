#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
bool dfs(int u, int c) {
    vis[u] = c;
    bool cur = 1;
    for (auto &v : adj[u]) {
        if (vis[v] == 0) {
            cur &= dfs(v, -c);
        }
        else if (vis[v] == c) cur = 0;
    }
    return cur;
}
int main() {
    int t; cin >> t;
    int T = t;
    while (t--) {
        int n, m; cin >> n >> m;
        adj.assign(n + 1, {});
        vis.assign(n + 1,  0);
        for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool possible = 1;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 0) {
                possible &= dfs(i, -1);
            }
        }
        cout << "Scenario #" << T - t << ":\n";
        if (possible)
            cout << "No suspicious bugs found!\n";
        else
            cout << "Suspicious bugs found!\n";
    }
}