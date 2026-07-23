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

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, k, d; cin >> n >> k >> d;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<bool> vis(n + 1);
    vector<int> used(n);
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
        int x; cin >> x;
        vis[x] = 1;
        q.push(x);
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &[v, idx] : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
                used[idx] = 1;
            }
        }
    }
    vector<int> ans;
    for (int i = 1; i < n; ++i) if (!used[i]) ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); ++i) cout << ans[i] << " \n"[i == (int) ans.size() - 1];
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}