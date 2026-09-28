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

vector<vector<int>> adj;
vector<int> depth;
vector<int> sz;
vector<int> mx;

void dfs(int u, int p) {
    sz[u] = 1;
    mx[u] = depth[u];
    for (auto &v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
            mx[u] = max(mx[u], mx[v]);
        }
    }
}

void solve() {
    int n; cin >> n;
    depth.assign(n + 1, 0);
    adj.assign(n + 1, {});
    sz.assign(n + 1, 0);
    mx.assign(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);

    vector<int> set(n);
    for (int i = 0; i < n; ++i) set[i] = i + 1;
    sort(all(set), [](int a, int b) {
        return mx[a] < mx[b];
    });
    int cur = 0;
    int ans = LLONG_MAX;

    vector<int> prefix(n + 2, 0);
    for (int i = 1; i <= n; ++i) {
        prefix[depth[i] + 1]++;
    }
    for (int i = 1; i <= n + 1; ++i) {
        prefix[i] += prefix[i - 1];
    }
    for (int d = 0; d <= mx[1]; ++d) {
        while (cur < n and mx[set[cur]] < d) {
            cur++;
        }
        int kept = prefix[d + 1] - cur;
        ans = min(ans, n - kept);
    }
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