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
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

vector<vector<int>> adj;
vector<int> vis;
vector<int> topological;
bool notCycle = 1;

void dfs(int u) {
    vis[u] = 2;
    for (auto v : adj[u]) if (!vis[v]) dfs(v); else if (vis[v] == 2) notCycle = 0;
    topological.push_back(u);
    vis[u] = 1;
}

void solve() {
    int n, m; cin >> n >> m;

    adj.assign(n + 1, {});
    vis.assign(n + 1,  0);
    topological.clear();

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);

    // if (cycle) for (int i = (int) topological.size() - 1; i >= 0; --i) cout << topological[i] << " \n"[i == 0];
    if (notCycle) cout << topological << endl;
    else cout << "-1\n";
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef LOCAL
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}