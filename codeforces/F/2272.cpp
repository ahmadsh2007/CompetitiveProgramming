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

void solve() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> down(n + 1), up(n + 1), h(n + 1), c(n + 1), parent(n + 1);
    auto dfs1 = [&](this auto&& self, int u, int p) -> void {
        parent[u] = p;
        c[u] = 0;
        h[u] = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            self(v, u);
            c[u]++;
            h[u] += (down[v] == 0);
        }
        down[u] = (h[u] > 0 or c[u] % 2 == 0);
    };

    auto dfs2 = [&](this auto&& self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v != p) {
                up[v] = !((p == 0 or up[u] == 1) and
                          (h[u] - (down[v] == 0) == 0) and
                          ((int) adj[u].size() % 2 == 0));
                self(v, u);
            }
        }
    };

    dfs1(1, 0);
    dfs2(1, 0);

    vector<int> g;
    for (int i = 1; i <= n; ++i) {
        if (!(h[i] > 0 or (parent[i] != 0 and up[i] == 0) or ((int) adj[i].size() % 2))) {
            g.push_back(i);
        }
    }

    if (g.empty()) {
        return void(cout << "Alice\n");
    }

    cout << "Bob\n" << (int) g.size() << endl;
    cout << g << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}