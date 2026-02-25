#include <bits/stdc++.h>
using namespace std;

#define ll long long

void edgeList() {
    int n, m; cin >> n >> m;
    
    // vector<pair<int, int>> edgeList(m);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> edgeList[i].first >> edgeList[i].second;
    // }

    set<pair<int, int>> edgeList;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        edgeList.insert({u, v});
        edgeList.insert({v, u});
    }
}

void matrix() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mat[i][j] << " \n"[j == n];
        }
    }
}

void adjacency() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ' ';
        for (auto u : adj[i])
        {
            cout << u << ' ';
        }
        cout << endl;
    }
}

void solve() {
    adjacency();
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}