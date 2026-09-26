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

const int LOG = 30;

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> lca(n + 1, vector<int>(LOG, 0));
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
                lca[v][0] = u;
                for (int i = 1; i < LOG; ++i) {
                    lca[v][i] = lca[lca[v][i - 1]][i - 1];
                }
                dfs(dfs, v, u);
            }
        }
    };

    dfs(dfs, 1, 0);

    int q; cin >> q;
    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        int aa = a, bb = b;
        
        if (depth[b] > depth[a]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int i = 0; i < LOG; ++i) {
            if (diff & (1 << i)) {
                a = lca[a][i];
            }
        }

        int root = a;
        if (a != b) {
            for (int i = LOG - 1; i >= 0; --i) {
                if (lca[a][i] != lca[b][i]) {
                    a = lca[a][i];
                    b = lca[b][i];
                }
            }
            root = lca[a][0];
        }

        int d1 = depth[aa] - depth[root];
        int d2 = depth[bb] - depth[root];
        int d = d1 + d2;
        
        if (c >= d) {
            cout << bb << endl;
        }
        else if (d1 >= c) {
            for (int i = 0; i < LOG; ++i) {
                if (c & (1 << i)) {
                    aa = lca[aa][i];
                }
            }
            cout << aa << endl;
        }
        else {
            c = d - c;
            for (int i = 0; i < LOG; ++i) {
                if (c & (1 << i)) {
                    bb = lca[bb][i];
                }
            }
            cout << bb << endl;
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