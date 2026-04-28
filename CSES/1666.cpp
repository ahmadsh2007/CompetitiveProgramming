/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> adj;
vector<vector<int>> comp;
vector<int> temp;
vector<bool> vis;

void dfs(int u) {
    vis[u] = 1;
    temp.push_back(u);
    for (auto v : adj[u]) if (!vis[v]) {
        dfs(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;

    adj.resize(n + 1, {});
    vis.resize(n + 1,  0);
    comp.clear();
    temp.clear();

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            comp.push_back(temp);
            temp.clear();       
        }
    }

    cout << (int) comp.size() - 1 << endl;
    for (int i = 1; i < (int) comp.size(); ++i) cout << comp[i][0] << ' ' << comp[i - 1][0] << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}