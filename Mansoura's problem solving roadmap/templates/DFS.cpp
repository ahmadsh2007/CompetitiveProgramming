#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dfs(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        dfs[u].push_back(v);
        dfs[v].push_back(u);
    }

    // Approach for dfs, recursive
    /*
        DFS (node u)
        {
            vis[u] = 1
            for each node v in adj[u]
                if vis[v] == 0
                    DFS (v)
        }
    */
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}