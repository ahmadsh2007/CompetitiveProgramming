/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
// #define int long long
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
    int grid[n + 1][m + 1] = {0};
    bool vis[n + 1][m + 1] = {0};
    int k; cin >> k;
    vector<pair<int, int>> b(k);
    for (int i = 0; i < k; ++i) cin >> b[i].first >> b[i].second;

    queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i) q.push(b[i]), vis[b[i].first][b[i].second] = 1;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = u.first + dy[i];
            int nx = u.second+ dx[i];
            if (ny < 1 or ny > n or
                nx < 1 or nx > m or
                vis[ny][nx]) continue;

            grid[ny][nx] = grid[u.first][u.second] + 1;
            vis[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    int mx = -1;
    int x, y;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (grid[i][j] > mx) {
                x = i, y = j;
                mx = grid[i][j];
            }
        }
    }

    cout << x << ' ' << y << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}