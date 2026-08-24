#include <bits/stdc++.h>
using namespace std;

#define str string

const int N = 300005;
const int LN = 20;

vector<int> adj[N];
int up[N][LN];
int depth[N], sz[N];

void dfs(int u, int p, int d) {
    depth[u] = d;
    sz[u] = 1;
    up[u][0] = p;
    for (int j = 1; j < LN; ++j) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
            sz[u] += sz[v];
        }
    }
}

int get_kth_ancestor(int u, int k) {
    for (int j = 0; j < LN; ++j) {
        if ((k >> j) & 1) {
            u = up[u][j];
        }
    }
    return u;
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    u = get_kth_ancestor(u, depth[u] - depth[v]);
    if (u == v) return u;

    for (int j = LN - 1; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

void solve() {
    int n, q; cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 1, 0);

    while (q--) {
        int u, v;
        cin >> u >> v;

        if (u == v) {
            cout << n << endl;
            continue;
        }

        int lca = get_lca(u, v);
        int dist = depth[u] + depth[v] - 2 * depth[lca];

        if (dist % 2) {
            cout << 0 << endl;
            continue;
        }

        int mid = dist / 2;

        if (depth[u] == depth[v]) {
            int uChild = get_kth_ancestor(u, mid - 1);
            int vChild = get_kth_ancestor(v, mid - 1);
            cout << n - sz[uChild] - sz[vChild] << endl;
        } else {
            if (depth[u] < depth[v]) swap(u, v);
            int m = get_kth_ancestor(u, mid);
            int uChild = get_kth_ancestor(u, mid - 1);
            cout << sz[m] - sz[uChild] << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("library.in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}