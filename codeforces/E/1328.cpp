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
const int LOG = 20;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> lca(LOG, vector<int>(n + 1));
    vector<int> depth(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](auto dfs, int u, int p) -> void {
        for (auto &v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                lca[0][v] = u;
                for (int i = 1; i < LOG; ++i) {
                    lca[i][v] = lca[i - 1][lca[i - 1][v]];
                }
                dfs(dfs, v, u);
            }
        }
    };

    dfs(dfs, 1, 0);

    auto getLCA = [&](int a, int b) -> int {
        int diff = depth[a] - depth[b];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) {
                a = lca[i][a];
            }
        }
        for (int i = LOG - 1; i >= 0; --i) {
            if (lca[i][a] != lca[i][b]) {
                a = lca[i][a];
                b = lca[i][b];
            }
        }
        return lca[0][a];
    };

    while (m--) {
        int k; cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; ++i) {
            cin >> v[i];
        }
        sort(all(v), [&](int a, int b) {
            return depth[a] > depth[b];
        });

        bool ans = true;
        for (int i = 0; i < k - 1; ++i) {
            int a = v[i], b = v[i + 1];
            int lca = getLCA(a, b);
            if (lca != a and lca != b and depth[a] - depth[lca] > 1 and depth[b] - depth[lca] > 1) {
                ans = false;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << endl;
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