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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<int>> adj;
map<int, vector<int>> pot;
map<int, char> alice;
str s;
void dfs(int u, int p) {
    for (auto &v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

void solve() {
    int n; cin >> n;
    adj.assign(n + 1, {});
    pot.clear();
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;
    for (auto &u : adj[1]) {
        dfs(u, 1);
    }

    bool turn = false;
    int cnt[4] = {0, 0, 0, 0};
    for (int i = 2; i <= n; ++i) {
        if ((int) adj[i].size() == 1) {
            if (s[i - 1] == '1') cnt[1]++;
            else if (s[i - 1] == '0') cnt[0]++;
            else cnt[2]++;
        }
        else if (s[i - 1] == '?') cnt[3]++;
    }
    
    if (s[0] != '?') {
        cout << ((s[0] == '1' ? cnt[0] : cnt[1]) + (cnt[2] + 1) / 2) << endl;
    } else {
        if (cnt[0] == cnt[1] and (cnt[3] % 2 == 1)) {
            cout << (cnt[0] + (cnt[2] + 1) / 2) << endl;
        } else {
            cout << (max(cnt[0], cnt[1]) + cnt[2] / 2) << endl;
        }
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