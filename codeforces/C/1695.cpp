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
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    // dp[i][j][0] == minimum path, dp[i][j][1] == maximum path
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    if ((n + m - 1) % 2) {
        return void(cout << "NO" << endl);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j][0] = INF;
            dp[i][j][1] = -INF;
        }
    }
    dp[0][0][0] = dp[0][0][1] = g[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i) {
                dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][0] + g[i][j], dp[i - 1][j][1] + g[i][j]});
                dp[i][j][1] = max({dp[i][j][1], dp[i - 1][j][0] + g[i][j], dp[i - 1][j][1] + g[i][j]});
            }
            if (j) {
                dp[i][j][0] = min({dp[i][j][0], dp[i][j - 1][0] + g[i][j], dp[i][j - 1][1] + g[i][j]});
                dp[i][j][1] = max({dp[i][j][1], dp[i][j - 1][0] + g[i][j], dp[i][j - 1][1] + g[i][j]});
            }
        }
    }

    cout << (dp[n - 1][m - 1][0] <= 0 and dp[n - 1][m - 1][1] >= 0 ? "YES" : "NO") << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}