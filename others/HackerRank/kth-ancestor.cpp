#include <bits/stdc++.h>
using namespace std;
const int LOG = 21;
int main() {
    int t; cin >> t;
    while (t--) {
        int p; cin >> p;
        map<int, vector<int>> adj;
        unordered_set<int> have;
        int root = -1;
        for (int i = 1; i <= p; ++i) {
            int u, v; cin >> u >> v;
            have.insert(u);
            if (v == 0) {
                root = u;
                continue;
            }
            have.insert(v);
            adj[v].push_back(u);
        }
        map<int, map<int, int>> lca;
        auto dfs = [&](auto dfs, int u, int p) -> void {
            for (auto &v : adj[u]) {
                if (v != p) {
                    lca[v][0] = u;
                    for (int i = 1; i < LOG; ++i) {
                        lca[v][i] = lca[lca[v][i - 1]][i - 1];
                    }
                    dfs(dfs, v, u);
                }
            }
        };
        dfs(dfs, root, 0);
        int q; cin >> q;
        while (q--) {
            int op; cin >> op;
            if (op == 0) {
                int v, u; cin >> v >> u;
                adj[v].push_back(u);
                lca[u][0] = v;
                for (int i = 1; i < LOG; ++i) {
                    lca[u][i] = lca[lca[u][i - 1]][i - 1];
                }
                have.insert(u);
            }
            else if (op == 1) {
                int u; cin >> u;
                have.erase(u);
            }
            else {
                int u, k; cin >> u >> k;
                if (have.find(u) == have.end()) {
                    cout << 0 << endl;
                    continue;
                }
                for (int i = 0; i < LOG; ++i) {
                    if (k & (1 << i)) {
                        u = lca[u][i];
                    }
                }
                cout << u << endl;
            }
        }
    }
}