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


void solve() {
    int n, m; cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    vector<int> distance(n + 1, 1e9);

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    distance[1] = 1;
    q.push(1);
    visited[1] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) {
            if (visited[v]) continue;
            visited[v] = 1;
            distance[v] = min(distance[v], distance[u] + 1);
            q.push(v);
        }
    }

    vector<int> ans = {n};
    for (int i = 1; i <= n; ++i) visited[i] = 0;

    q.push(n);
    visited[n] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) {
            if (visited[v]) continue;

            visited[v] = 1;
            if (distance[v] == distance[u] - 1) {
                ans.push_back(v);
                while (!q.empty()) q.pop();
                q.push(v);
                break;
            }
        }
    }

    if (distance[n] == 1e9) cout << "IMPOSSIBLE\n";
    else {
        cout << distance[n] << endl;
        for (int i = (int) ans.size() - 1; i >= 0; --i) cout << ans[i] << " \n"[i == 0];
    }
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}