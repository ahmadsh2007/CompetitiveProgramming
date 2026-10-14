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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (adj[i].empty()) {
            return void(cout << "Brain Melt" << endl);
        }
    }

    vector<int> depth(n + 1);
    auto dfs = [&](this auto&& dfs, int u) -> void{
        vis[u] = 1;
        for (auto &v : adj[u]) {
            if (!vis[v]) {
                depth[v] = depth[u] + 1;
                dfs(v);
            }
        }
    };

    dfs(1);

    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].empty()) {
            return void(cout << "Brain Melt\n");
        }
        mx = max(mx, (int) adj[i].size());
    }

    if (mx == n - 1 and m + 1 == n) {
        cout << 2 << endl;
    }
    else {
        cout << "Many" << endl;
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