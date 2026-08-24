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

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> adj;
vector<bool> vis;
int ans;
str s;

int dfs(int u) {
    vis[u] = true;
    int b = 0;
    if (s[u - 1] == 'B') b++;
    else b--;
    
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            b += dfs(v);
        }
    }
    
    if (!b) ans++;
    return b;
}

void solve() {
    int n; cin >> n;
    
    ans = 0;
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        int u; cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }

    cin >> s;

    dfs(1);

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}