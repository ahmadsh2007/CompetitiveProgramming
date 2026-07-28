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

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Industries {
    int score;
    int index;
};

vector<vector<int>> adj;
vector<int> sz;
vector<int> depth;
vector<bool> vis;
vector<bool> isI;

void dfs(int u) {
    vis[u] = 1;
    sz[u] = 1;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            depth[v] = depth[u] + 1;
            dfs(v);
            sz[u] += sz[v];
        }
    }
}
void dfs2(int u, int c, int & ans) {
    if (isI[u]) ans += c;
    else c++;
    vis[u] = 1;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs2(v, c, ans);
        }
    }
}
void solve() {
    int n, k; cin >> n >> k;
    adj.assign(n + 1, {});
    sz.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    isI.assign(n + 1, 0);

    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) vis[i] = 0;

    vector<Industries> ind; 
    for (int i = 1; i <= n; ++i) {
        ind.push_back({depth[i] - (sz[i] - 1), i});
    }
    sort(rall(ind), [](const Industries & i1, const Industries & i2) {
        if (i1.score != i2.score) return i1.score < i2.score;
        return i1.index < i2.index;

    });
    for (int i = 0; i < k; ++i) {
        isI[ind[i].index] = 1;
    }
    int ans = 0;
    dfs2(1, 0, ans);

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}