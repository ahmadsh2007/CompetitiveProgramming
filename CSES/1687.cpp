#include <bits/stdc++.h>
using namespace std;
const int LOG = 21;
vector<vector<int>> adj;
vector<vector<int>> lca;
vector<int> depth;
int n, q;
void dfs(int u) {
    for (auto &v : adj[u]) {
        depth[v] = depth[u] + 1;
        for (int i = 1; i < LOG; ++i) {
            lca[v][i] = lca[lca[v][i - 1]][i - 1];
        }
        dfs(v);
    }
}
int main() {
    cin >> n >> q;
    depth.assign(n + 1, 0);
    lca.assign(n + 1, vector<int>(LOG));
    adj.assign(n + 1, {});
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        adj[p].push_back(i);
        lca[i][0] = p;
    }
    dfs(1);
    while (q--) {
        int x, k; cin >> x >> k;
        if (depth[x] < k) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < LOG; ++i) {
            if (k & (1 << i)) {
                x = lca[x][i];
            }
        }
        cout << x << endl;
    }
}