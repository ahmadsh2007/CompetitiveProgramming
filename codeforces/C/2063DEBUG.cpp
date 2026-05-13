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

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) (int)(x).size()
// #define endl '\n'
// #define int long long
// #define str string // What a Python

// #define vi   vector<int>
// #define vill vector<ll>
// #define read(v) for (auto &x : v) cin >> x;
// #define cin(v)  for (auto &x : v) cin >> x;
// #define cout(v) for (auto &x : v) cout << x << ' ';

// using ll  = long long;
// using ull = unsigned long long;

// using u128 = unsigned __int128;
// using i128 = __int128;

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

    auto findBiggest = [&](int ignore = 0) -> int {
        int mx = -1;
        int idx= 0;
        for (int i = 1; i <= n; ++i) if (i != ignore && !vis[i] && (int) adj[i].size() - sub[i] > mx) mx = (int) adj[i].size() - sub[i], idx = i;
        
        return idx;
    };
    
    vector<int> topThree;
    for (int i = 0; i < 3; ++i) {
        int cur = findBiggest();
        vis[cur] = 1;
        topThree.push_back(cur);
    }

    int ans = 0;
    for (int j = 0; j < 3; ++j) {
        vector<vector<int>> temp = adj;
        for (int i = 1; i <= n; ++i) vis[i] = 0;
        for (int i = 1; i <= n; ++i) sub[i] = 0;

        int cur = findBiggest(topThree[j]);
        vis[cur] = 1;
        for (int i = 0; i < 2; ++i) {
            for (auto v : temp[cur]) if ((int) temp[v].size() - sub[v] != 0) sub[v]++;
        }
        temp[cur].clear();

        int curAns = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                dfs(i, vis, temp);
                curAns++;
            }
        }

        ans = max(ans, curAns);
    }

    cout << ans << endl;
}

// const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    // ull TTT = 1;
    // if (TESTCASES == 1) cin >> TTT;
    // else if (TESTCASES == 2) {
    // #ifndef LOCAL
    //   cin >> TTT;
    // #endif
    // }
    // while (TTT--) 
    solve();
    return 0;
}