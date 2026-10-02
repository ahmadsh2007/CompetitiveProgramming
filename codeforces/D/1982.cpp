/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    vector<string> snowy(n + 1, string(m + 1, 'x'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        str s; cin >> s;
        s = 'x' + s;
        snowy[i] = s;
    }
    int sum[2] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[snowy[i][j] == '1'] += grid[i][j];
        }
    }
    vector<vector<array<int, 2>>> prefix(n + 1, vector<array<int, 2>>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            prefix[i][j][0] = prefix[i - 1][j][0] + prefix[i][j - 1][0] + (snowy[i][j] == '0') - prefix[i - 1][j - 1][0];
            prefix[i][j][1] = prefix[i - 1][j][1] + prefix[i][j - 1][1] + (snowy[i][j] == '1') - prefix[i - 1][j - 1][1];
        }
    }

    vector<int> sets;
    for (int i = k; i <= n; ++i) {
        for (int j = k; j <= m; ++j) {
            int v1 = prefix[i][j][0] - prefix[i - k][j][0] - prefix[i][j - k][0] + prefix[i - k][j - k][0];
            int v2 = prefix[i][j][1] - prefix[i - k][j][1] - prefix[i][j - k][1] + prefix[i - k][j - k][1];
            sets.push_back(abs(v1 - v2));
        }
    }

    int tot = abs(sum[0] - sum[1]);
    int g = 0;
    for (const int &s : sets) {
        g = gcd(g, s);
    }
    cout << (tot == 0 or (g != 0 and tot % g == 0) ? "YES\n" : "NO\n");
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}