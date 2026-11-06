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

    if (n % 2 == 0) {
        return void(cout << n + 1 << endl);
    }

    auto test = [&](int target) -> pair<int, int> {
        // 1 grey, 2 black
        vector<int> colors(n + 1);
        for (int i = 1; i <= target; ++i) {
            if (target == 2 * i) continue;
            if (i <= n and target - i >= 1 and target - i <= n) {
                colors[i] = 2;
                colors[target - i] = 2;
            }
        }

        int node;
        for (int i = 1; i <= n; ++i) {
            if (colors[i] == 0) {
                node = i;
            }
        }

        vector<int> comp(n + 1);
        auto dfs = [&](this auto&& self, int u, int p, int c) -> void {
            comp[u] = c;
            for (auto &v : adj[u]) {
                if (v != p) {
                    self(v, u, c);
                }
            }
        };
        int c = 1;
        for (int i = 0; i < (int) adj[node].size(); ++i) {
            dfs(adj[node][i], node, c++);
        }

        for (int i = 1; i <= target; ++i) {
            if (target == 2 * i) continue;
            if (i <= n and target - i >= 1 and target - i <= n) {
                if (comp[i] != comp[target - i]) {
                    return {n - 1, 1};
                }
            }
        }

        return {n - 1, 0};
    };

    pair<int, int> ans = {0, 0};
    int print = 0;
    for (int i = 0; i <= 2; ++i) {
        int target = n + i;
        pair<int, int> cur = test(target);
        if (cur.first > ans.first or (cur.first == ans.first and cur.second > ans.second)) {
            ans = cur;
            print = target;
        }
    }

    cout << print << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}