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

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct Edge {
    int to;
    int id;
};

int n, m;
vector<int> d;
vector<vector<Edge>> adj;
vector<bool> vis;
vector<int> ans;

int dfs(int u) {
    vis[u] = 1;
    int curEdgeNeeded = d[u];
    for (auto & v : adj[u]) {
        if (!vis[v.to]) {
            if (dfs(v.to) == 1) {
                ans.push_back(v.id);
                curEdgeNeeded ^= 1;
            }
        }
    }
    return curEdgeNeeded;
}

void solve() {
    int n, m; cin >> n >> m;
    d.assign(n + 1, 0);
    adj.assign(n + 1, {});
    vis.assign(n + 1,  0);
    int sum = 0;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 1; i <= n; ++i) if (d[i] > 0) sum++;
    for (int i = 1; i <= n; ++i) {
        if (d[i] < 0) {
            if (sum & 1) {
                sum++;
                d[i] = 1;
            }
            else d[i] = 0;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    if (sum & 1) return void(cout << -1 << endl);
    dfs(1);
    cout << (int) ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) cout << ans[i] << " \n"[i == (int) ans.size() - 1];
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}