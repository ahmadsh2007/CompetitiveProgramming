/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;
 
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
 
static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();
 
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
 
void dfs(int r, int c) {
    visited[r][c] = 1;
 
    for (int i = 0; i < 4; ++i) {
        int nr = r + dx[i];
        int nc = c + dy[i];
 
        if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
            if (grid[nr][nc] == '.' && !visited[nr][nc]) {
                dfs(nr, nc);
            }
        }
    }
}
 
void solve() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m));
 
    for (int i = 0; i < n; ++i) cin >> grid[i];
 
    int roomCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                roomCount++;
                dfs(i, j);
            }
        }
    }
 
    cout << roomCount << endl;
}
 
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
 
    solve();
    return 0;
}
