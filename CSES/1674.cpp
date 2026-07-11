#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> ans;
int dfs(int u) {
    if (vis[u]) return 0;
    for (auto v : adj[u]) {
        ans[u] += dfs(v);
    }
    return ans[u] + 1;
}
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    adj.assign(n + 1, {});
    vis.assign(n + 1,  0);
    ans.assign(n + 1,  0);
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}