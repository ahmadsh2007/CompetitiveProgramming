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
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    vector<vector<int>> dist(n + 1, vector<int>(2, INF));
    int start_node = 1; 
    dist[start_node][0] = 0;

    // Priority Queue: stores {distance, node}
    // greater<> makes it a min-priority queue (smallest distance first)
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int,int>>>> pq;

    pq.push({0, {start_node, 0}});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second.first;
        int used = pq.top().second.second;
        pq.pop();

        // Optimization: If we found a shorter path already, skip this stale entry
        if (d > dist[u][used]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v][used] > d + weight) {
                dist[v][used] = dist[u][used] + weight;
                pq.push({dist[v][used], {v, used}});
            }

            if (used == 0) {
                if (dist[v][1] > d + weight / 2) {
                    dist[v][1] = d + weight / 2;
                    pq.push({dist[v][1], {v, 1}});
                }
            }
        }
    }

    // Output distances (Example: from node 1 to node n)
    cout << dist[n][1] << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}