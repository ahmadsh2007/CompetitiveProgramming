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

#define vi   vector<int>
#define vill vector<ll>

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int n, m;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> a;
int dfs(int u, int c) {
    int cur = 0;
    vis[u] = 1;
    if (c > m) return 0;
    if (adj[u].size() == 1 && u != 1) return 1;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            if (a[v]) {
                cur += dfs(v, c + 1);
            }
            else {
                cur += dfs(v, 0);
            }
        }
    }
    return cur;
}
void solve() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    vis.assign(n + 1,  0);
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = dfs(1, a[1]);
    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}