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
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int N = 1000405;
const int NRows = 1415;
vector<vector<int>> rows(NRows);
vector<vector<int>> adj(N + 1);

static const int BUILD = [](){
    int val = 1;
    for (int i = 1; val <= N; ++i) {
        for (int j = 0; j < i; ++j)
            rows[i].push_back(val++);
    }

    for (int i = NRows - 1; i > 1; --i) {
        for (int j = 0; j < (int) rows[i].size(); ++j) {
            if (j == 0) adj[rows[i][j]].push_back(rows[i - 1][j]);
            else if (j == (int) rows[i].size() - 1) {
                adj[rows[i][j]].push_back(rows[i - 1][j - 1]);
            }
            else {
                adj[rows[i][j]].push_back(rows[i - 1][j - 1]);
                adj[rows[i][j]].push_back(rows[i - 1][j]);
            }
        }
    }
    return 0;
}();

vector<int> ans(N + 1);

static const int PRECOMPUTE_MEMO = []() {
    ans[1] = 1;
    for (int i = 2; i <= N; ++i) {
        int res = i * i;
        if (adj[i].size() == 1) {
            res += ans[adj[i][0]];
        } else if (adj[i].size() == 2) {
            res += ans[adj[i][0]] + ans[adj[i][1]] - ans[adj[adj[i][1]][0]];
        }
        ans[i] = res;
    }
    return 0;
}();

void solve() {
    int n; cin >> n;

    cout << ans[n] << endl;
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