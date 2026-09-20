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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    array<int, 2> S, T;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') S = {i, j};
            if (grid[i][j] == 'T') T = {i, j};
        }
    }

    vector<vector<vector<array<int, 4>>>> dp(n, vector<vector<array<int, 4>>>(m, vector<array<int, 4>>(5, {-1, -1, -1, -1})));
    queue<array<int, 4>> q;
    q.push({S[0], S[1], 4, 0});
    dp[S[0]][S[1]][4][0] = 0;
    int ans = -1;
    while (!q.empty()) {
        array<int, 4> cur = q.front();
        q.pop();

        if (cur[0] == T[0] and cur[1] == T[1]) {
            ans = dp[cur[0]][cur[1]][cur[2]][cur[3]];
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int ny = dy[i] + cur[0];
            int nx = dx[i] + cur[1];
            if (ny < 0 or ny >= n or nx < 0 or nx >= m or grid[ny][nx] == '#') continue;

            int ncnt = (i == cur[2] ? cur[3] + 1 : 1);
            if (ncnt > 3) continue;

            if (dp[ny][nx][i][ncnt] == -1) {
                dp[ny][nx][i][ncnt] = dp[cur[0]][cur[1]][cur[2]][cur[3]] + 1;
                q.push({ny, nx, i, ncnt});
            }
        }
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}