/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

template<class T>istream& operator>>(istream& in, vector<T>& v){for(auto& x:v) in>>x;return in;}
template<class T>ostream& operator<<(ostream& out, vector<T>& v){for(auto& x:v) out<<x<<' ';return out;}

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const long long INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    str crw = "crewmate";
    str imp = "imposter";

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int k = 0; k < m; k++) {
        int i, j; cin >> i >> j;
        str s; cin >> s;
        int w = (s == imp);
        adj[i].push_back({j, w});
        adj[j].push_back({i, w});
    }
    
    // crewmate = 0, imposter = 1
    vector<int> c(n + 1, -1);
    bool ok = true;
    int cnt[2];
    auto dfs = [&](this auto&& self, int u) -> void {
        cnt[c[u]]++;
        for (auto [v, w] : adj[u]) {
            int need = c[u] ^ w;
            if (c[v] == -1) {
                c[v] = need;
                self(v);
            } else if (c[v] != need) {
                ok = false;
            }
        }
    };

    int ans = 0;
    for (int u = 1; u <= n; u++) {
        if (c[u] == -1) {
            cnt[0] = cnt[1] = 0;
            c[u] = 0;
            dfs(u);
            ans += max(cnt[0], cnt[1]);
        }
    }

    cout << (ok ? ans : -1) << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}