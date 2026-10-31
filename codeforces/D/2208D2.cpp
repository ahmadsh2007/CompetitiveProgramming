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

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 8001;
bitset<N> R[N], G[N];

void solve() {
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        R[i].reset();
        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == '1') {
                R[i][j] = 1;
            }
        }
        cnt[i] = R[i].count();
    }

    vector<int> ord(n);
    iota(all(ord), 1);
    sort(all(ord), [&](int a, int b) { return cnt[a] > cnt[b]; });

    vector<vector<int>> adj(n + 1);
    int tot = 0;
    for (int u = 1; u <= n and tot <= n - 1; ++u) {
        bitset<N> cov;
        for (int v : ord) {
            if (v == u || !R[u][v] || cov[v]) continue;
            adj[u].push_back(v);
            cov |= R[v];
            if (++tot > n - 1) break;
        }
    }

    if (tot != n - 1) {
        return void(cout << "No\n");
    }

    auto check = [&]() -> bool {
        vector<vector<int>> list(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < (int) adj[i].size(); ++j) {
                list[i].push_back(adj[i][j]);
                list[adj[i][j]].push_back(i);
            }
        }

        vector<int> vis(n + 1);
        auto dfs = [&](this auto&& self, int u) -> void {
            vis[u] = 1;
            for (auto &v : list[u]) {
                if (!vis[v]) {
                    self(v);
                }
            }
        };

        dfs(1);

        bool res = true;
        for (int i = 1; i <= n; ++i) {
            res &= vis[i];
        }

        return res;
    };

    if (!check()) {
        return void(cout << "No\n");
    }

    vector<int> done(n + 1);
    auto calc = [&](this auto&& self, int u) -> void {
        done[u] = 1;
        G[u].reset();
        G[u][u] = 1;
        for (int v : adj[u]) {
            if (!done[v]) self(v);
            G[u] |= G[v];
        }
    };
    for (int u = 1; u <= n; ++u) if (!done[u]) calc(u);
    for (int u = 1; u <= n; ++u) {
        if (G[u] != R[u]) return void(cout << "No\n");
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int) adj[i].size(); ++j) {
            cout << i << ' ' << adj[i][j] << endl;
        }
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}