#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define str string

vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> parent;
vector<vector<int>> levels;
vector<bool> vis;

void dfs(int u, int d, int p, int w) {
    vis[u] = true;
    levels[d].push_back(u);
    parent[u] = {p, w};

    for (auto &v: adj[u]) {
        if (!vis[v.first]) {
            dfs(v.first, d + 1, u, v.second);
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    levels.assign(n + 1, {});
    parent.assign(n + 1, {});
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int tot = accumulate(a.begin(), a.end(), 0ll);
    if (tot % k) {
        return void(cout << -1 << endl);
    }

    dfs(1, 1, 0, 0);

    int ans = 0;
    for (int l = n; l > 0; --l) {
        if (levels[l].empty()) {
            continue;
        }

        for (int i = 0; i < (int) levels[l].size(); ++i) {
            if (levels[l][i] == 1) continue;
            
            int remaining = a[levels[l][i]] % k;
            if(remaining<0)
            remaining+=k;
           
            if (remaining < k - remaining) {
                a[levels[l][i]] -= remaining;
                a[parent[levels[l][i]].first] += remaining;
                ans += parent[levels[l][i]].second * remaining;
            }
            else {
                a[levels[l][i]] += (k - remaining);
                a[parent[levels[l][i]].first] -= (k - remaining);
                ans += parent[levels[l][i]].second * (k - remaining);
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}