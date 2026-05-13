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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int u, vector<bool> & vis, vector<vector<int>> & adj) {
    vis[u] = 1;
    for (auto &v : adj[u]) if (!vis[v]) dfs(v, vis, adj);
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1);
    vector<int> sub(n + 1);
    
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n <= 2) { cout << "0\n"; return; }

    int ignore = -1;
    auto findBiggest = [&](int ignore = 0) -> int {
        int mx = -1;
        int idx= 0;
        for (int i = 1; i <= n; ++i) if (i != ignore && !vis[i] && (int) adj[i].size() - sub[i] > mx) mx = (int) adj[i].size() - sub[i], idx = i;
        
        return idx;
    };
    
    vector<int> candidates;
    for (int i = 0; i < 3; ++i) {
        int cur = findBiggest(0);
        candidates.push_back(cur);
        vis[cur] = 1; 
    }

    for (int i = 1; i <= n; i++) { vis[i] = 0; sub[i] = 0; }

    int ans = 0;
    for (int u : candidates) {
        for (auto v : adj[u]) sub[v] = 1;
        
        int v = findBiggest(u);
        
        ans = max(ans, (int)adj[u].size() + (int)adj[v].size() - sub[v] - 1);
        
        for (auto v : adj[u]) sub[v] = 0;
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
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