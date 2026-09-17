#include <bits/stdc++.h>
using namespace std;
const int LOG = 21;
vector<vector<int>> adj;
vector<vector<int>> lca;
vector<int> depth;
vector<int> vis;
int n, q;
void dfs(int u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            depth[v] = depth[u] + 1;
            for (int i = 1; i < LOG; ++i) {
                lca[v][i] = lca[lca[v][i - 1]][i - 1];
            }
            dfs(v);
        }
    }
}
int main() {
    cin >> n >> q;
    depth.assign(n + 1, 0);
    lca.assign(n + 1, vector<int>(LOG + 1));
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    while (q--) {
        int aRoot, bRoot; cin >> aRoot >> bRoot;
        int a = aRoot, b = bRoot;
        if (depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) {
                b = lca[b][i];
            }
        }
        for (int i = LOG - 1; i >= 0; --i) {
            if (a == b) break;
            a = lca[a][i];
            b = lca[b][i];
        }
        cout << depth[aRoot] + depth[bRoot] - 2 * depth[a] << endl;
    }
}