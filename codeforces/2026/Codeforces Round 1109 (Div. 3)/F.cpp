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

vector<vector<int>> adj;
vector<bool> vis;
vector<int> a;
bool flag;

pair<int, int> dfs(int u) {
    vis[u] = 1;
    if (a[u]) return {a[u], a[u]}; 
    vector<pair<int, int>> child;
    for (int v : adj[u]) {
        if (!vis[v]) {
            child.push_back(dfs(v));
        }
    }

    int m = (int) child.size();
    int cnt = 0;
    int start = 0;
    int end;
    for (int i = 0; i < m - 1; i++) {
        if (child[i].second > child[i + 1].first) {
            cnt++;
            start = i + 1;
        }
    }

    if (m > 1 && child[m - 1].second > child[0].first) {
        cnt++;
        start = 0;
    }
    if (cnt > 1) {
        flag = false;
        return {-1, -2};
    }

    if (!start) end = m - 1;
    else end = start - 1;
    return {child[start].first, child[end].second};
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, {});
    vis.assign(n + 1,  0);
    a.assign(n + 1, 0);
    flag = true; 
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i); 
    }    
    for (int i = 1; i <= n; i++) cin >> a[i];

    dfs(1);
    cout << (flag ? "YES\n" : "NO\n");
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}