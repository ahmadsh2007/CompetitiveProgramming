/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// Vector input/output operators
// I wish I could just do `v = list(map(int, input().split()))` instead of this boilerplate
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto& x:v) in>>x;
    return in;
}
// I wish I could just do `print(*v)` instead of this boilerplate
template<class T>
ostream& operator<<(ostream& out, vector<T>& v){
    for(auto& x:v) out<<x<<' ';
    return out;
}

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int LOG = 19;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> lca(LOG, vector<int>(n + 1, 0));
    vector<vector<int>> mns(LOG, vector<int>(n + 1, LLONG_MAX));
    vector<int> depth(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dfs = [&](auto dfs, int u, int p) -> void {
        for (auto &[v, w] : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                lca[0][v] = u;
                mns[0][v] = w;
                for (int i = 1; i < LOG; ++i) {
                    lca[i][v] = lca[i - 1][lca[i - 1][v]];
                    mns[i][v] = min(mns[i - 1][v], mns[i - 1][lca[i - 1][v]]);
                }
                dfs(dfs, v, u);
            }
        }
    };

    dfs(dfs, 1, 0);

    int q; cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        int ans = LLONG_MAX;
        if (depth[b] > depth[a]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) {
                ans = min(ans, mns[i][a]);
                a = lca[i][a];
            }
        }

        if (a == b) {
            cout << ans << endl;
        }
        else {
            for (int i = LOG - 1; i >= 0; --i) {
                if (lca[i][a] != lca[i][b]) {
                    ans = min({ans, mns[i][a], mns[i][b]});
                    a = lca[i][a];
                    b = lca[i][b];
                }
            }
            ans = min({ans, mns[0][a], mns[0][a]});
            cout << ans << endl;
        }
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}