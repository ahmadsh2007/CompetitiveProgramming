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
// #define int long long
#define str string // What a Python
  
using u128 = unsigned __int128;
using i128 = __int128;
 
const int MOD = 1e9 + 7;
 
static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();
 
char grid[1005][1005];
int parent_dir[1005][1005];
bool visited[1005][1005];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir_chars[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n, m; cin >> n >> m;

    pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr == end) { found = true; break; }

        for (int i = 0; i < 4; ++i) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && 
                grid[nx][ny] != '#' && !visited[nx][ny]) {
                
                visited[nx][ny] = true;
                parent_dir[nx][ny] = i;
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        string path = "";
        pair<int, int> curr = end;
        
        while (curr != start) {
            int d = parent_dir[curr.first][curr.second];
            path += dir_chars[d];
            curr = {curr.first - dx[d], curr.second - dy[d]};
        }
        
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        cout << path.length() << endl;
        cout << path << endl;
    }
}
 
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
 
    solve();
    return 0;
}
