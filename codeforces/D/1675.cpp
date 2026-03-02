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

vector<vector<int>> adj, comp;
vector<bool> vis;
vector<int> tmp;

void dfs(int u, int root) {
    vis[u] = 1;
    tmp.push_back(u);
    if ((int) adj[u].size() == 1 && u != root) {
        comp.push_back(tmp);
        tmp.clear();
    }
    for (auto v : adj[u]) if (!vis[v]) dfs(v, root);
}

void solve() {
    int n; cin >> n;
    vi p(n + 1);

    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    comp.clear();

    int root;
    for(int i = 1; i <= n ; ++i) {
        int x; cin >> x;
        if(x == i) root = x;
        else {
            adj[i].push_back(x);
            adj[x].push_back(i);
        } 
    }

    if (n == 1) { cout << "1\n1\n1\n\n"; return; }

    dfs(root, root);

    cout << (int) comp.size() << endl;
    for (int i = 0; i < (int) comp.size(); ++i) {
        cout << (int) comp[i].size() << endl;
        for (int j = 0; j < (int) comp[i].size(); ++j) cout << comp[i][j] << " \n"[j == (int) comp[i].size() - 1];
    }
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}