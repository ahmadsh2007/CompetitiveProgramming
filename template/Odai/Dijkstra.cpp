#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Competitive Programming Tip: 
 * Use long long for distances to avoid integer overflow.
 * CodeForces problems often have total path weights exceeding 2*10^9.
 */
const long long INF = 1e18; 

void solve() {
    int n, m; // n = nodes, m = edges
    cin >> n >> m;

    // Adjacency list: adj[u] = { {v1, w1}, {v2, w2}, ... }
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Remove this for directed graphs
    }

    vector<long long> dist(n + 1, INF);
    int start_node = 1; 
    dist[start_node] = 0;

    // Priority Queue: stores {distance, node}
    // greater<> makes it a min-priority queue (smallest distance first)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, start_node});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Optimization: If we found a shorter path already, skip this stale entry
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output distances (Example: from node 1 to node n)
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // Fast I/O is mandatory on CodeForces
    solve();
    return 0;
}