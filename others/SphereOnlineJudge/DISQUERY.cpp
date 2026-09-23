#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int LOG = 21;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> mnEdge, mxEdge;
vector<vector<int>> lca;
vector<int> depth;
vector<int> vis;
void dfs(int u) {
    vis[u] = 1;
    for (auto &[v, w] : adj[u]) {
        if (!vis[v]) {
            depth[v] = depth[u] + 1;
            lca[v][0] = u;
            mnEdge[v][0] = mxEdge[v][0] = w;
            for (int i = 1; i < LOG; ++i) {
                mnEdge[v][i] = min(mnEdge[v][i - 1], mnEdge[lca[v][i - 1]][i - 1]);
                mxEdge[v][i] = max(mxEdge[v][i - 1], mxEdge[lca[v][i - 1]][i - 1]);
                lca[v][i] = lca[lca[v][i - 1]][i - 1];
            }
            dfs(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    lca.assign(n + 1, vector<int>(LOG));
    mnEdge.assign(n + 1, vector<int>(LOG, 1e9));
    mxEdge.assign(n + 1, vector<int>(LOG, 0));
    adj.assign(n + 1, {});
    depth.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        int mn = 1e9;
        int mx = 0;
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) {
                mn = min(mn, mnEdge[u][i]);
                mx = max(mx, mxEdge[u][i]);
                u = lca[u][i];
            }
        }
        if (u == v) {
            cout << mn << ' ' << mx << endl;
            continue;
        }
        for (int i = LOG - 1; i >= 0; --i) {
            if (lca[u][i] != lca[v][i]) {
                mn = min({mn, mnEdge[u][i], mnEdge[v][i]});
                mx = max({mx, mxEdge[u][i], mxEdge[v][i]});
                u = lca[u][i];
                v = lca[v][i];
            }
        }
        mn = min({mn, mnEdge[u][0], mnEdge[v][0]});
        mx = max({mx, mxEdge[u][0], mxEdge[v][0]});
        cout << mn << ' ' << mx << endl;
    }
}