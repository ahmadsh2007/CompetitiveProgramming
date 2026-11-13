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

int n;
vector<int> f;
vector<int> sz;
vector<vector<int>> adj;

void dfs(int u, int p) {
    sz[u] = 1;
    int b1 = 0, b2 = 0;
    for (auto &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > b1) {
            b2 = b1;
            b1 = sz[v];
        }
        else if (sz[v] > b2) {
            b2 = sz[v];
        }
    }
    if (b1 == 0) {
        f[u] = 0;
        return;
    }
    f[u] = LLONG_MAX;
    for (auto &v : adj[u]) {
        if (v == p) continue;
        int other = (sz[v] == b1 ? b2 : b1);
        f[u] = min(f[u], max(f[v], other));
    }
}

void r2l() {
    dfs(1, 0);

    cout << n - f[1] << endl;
}
void l2l() {
    dfs(1, 0);

    vector<int> c(all(adj[1]));
    sort(all(c), [&](int u, int v) {
        return sz[u] > sz[v];
    });

    int loss = max({f[c[0]], f[c[1]], (int) c.size() > 2 ? sz[c[2]] : 0});
    cout << n - loss << endl;
}

void solve() {
    cin >> n;
    f.assign(n + 1, 0);
    sz.assign(n + 1, 0);
    adj.assign(n + 1, {});
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if ((int) adj[1].size() == 1) r2l();
    else l2l();
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}