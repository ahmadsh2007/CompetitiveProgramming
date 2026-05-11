#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;

    // Adjacency list: {neighbor, weight}
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // w is either 0 or 1
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INF);
    deque<int> dq;

    int start_node = 1;
    dist[start_node] = 0;
    dq.push_back(start_node);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                
                // The 0-1 Trick:
                if (weight == 0) {
                    dq.push_front(v); // High priority
                } else {
                    dq.push_back(v);  // Low priority
                }
            }
        }
    }

    // Output distance to node n
    if (dist[n] == INF) cout << -1 << endl;
    else cout << dist[n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}