// Time Complexity of DFS is O(V + E), O(n + m) in code underneath

#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<int>> adj;
vector<bool> vis;

void DFS(int u) {
    vis[u] = 1;
    // cout << u << endl;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);

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
    // * or
    /*
        DFS (node u)
        {
            if (vis[u] = 1) return
            vis[u] = 1
            for each node v in adj[u]
                DFS (v)
        }
    */
    // They do the same thing, same Big O, the only difference is that the second one has more calls. The first one is a little bit better
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}