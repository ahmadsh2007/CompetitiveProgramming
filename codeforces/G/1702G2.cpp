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
const long long LOG = 20;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> lca(LOG, vector<int>(n + 1));
    vector<int> depth(n + 1), tin(n + 1), tout(n + 1);
    int timer = 0;

    auto dfs = [&](this auto&& self, int u, int p) -> void {
        tin[u] = ++timer;
        lca[0][u] = p;
        for (int i = 1; i < LOG; ++i) {
            lca[i][u] = lca[i - 1][lca[i - 1][u]];
        }
        for (auto &v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                self(v, u);
            }
        }
        tout[u] = ++timer;
    };

    dfs(1, 1);

    auto isAncestor = [&](int a, int b) -> bool {
        return tin[a] <= tin[b] and tout[a] >= tout[b];
    };

    auto getLCA = [&](int a, int b) -> int {
        if (isAncestor(a, b)) return a;
        if (isAncestor(b, a)) return b;
        for (int i = LOG - 1; i >= 0; --i) {
            if (!isAncestor(lca[i][a], b)) {
                a = lca[i][a];
            }
        }
        return lca[0][a];
    };

    /*
    n = 5
    1 2
    2 3
    2 4
    4 5
    q = 5

    k = 3 YES
    3 2 5
    k = 5 NO
    1 2 3 4 5
    k = 2 YES
    1 4
    k = 3 NO
    1 3 5
    k = 3 YES
    1 5 4
    */

    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> cur(k);
        for (int i = 0; i < k; ++i) {
            cin >> cur[i];
        }
        sort(all(cur), [&](int a, int b) {
            return depth[a] > depth[b];
        });

        int u = cur[0];
        int v = -1;
        for (int i = 1; i < k; ++i) {
            if (!isAncestor(cur[i], u)) {
                v = cur[i];
                break;
            }
        }

        if (v == -1) {
            cout << "YES" << endl;
            continue;
        }

        int lca = getLCA(u, v);
        bool ok = true;
        for (const int & x : cur) {
            bool uBranch = isAncestor(x, u) and isAncestor(lca, x);
            bool vBranch = isAncestor(x, v) and isAncestor(lca, x);

            if (!uBranch and !vBranch) {
                ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
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