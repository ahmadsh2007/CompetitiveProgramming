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
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n, m; cin >> n >> m;
    vector<string> grid(1000 + 1);
    vector<vector<pair<int, int>>> parent(1001, vector<pair<int, int>>(1001));
    vector<vector<bool>> visited(1001, vector<bool>(1001));
    vector<vector<char>> move(1001, vector<char>(1001));
    vector<vector<int>> dis(1001, vector<int>(1001));
 
    for (int i = 0; i < n; ++i) cin >> grid[i];

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        move[i][j] = ' ';
        dis[i][j] = 1e9;
    }

    pair<int, int> A, B;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'A') A = {i, j};
        if (grid[i][j] == 'B') B = {i, j};
    }
 
    dis[A.first][A.second] = 0;
    visited[A.first][A.second] = 1;
    
    queue<pair<int, int>> q;
    q.push(A);

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (u == B) break;

        for (int i = 0; i < 4; ++i) {
            int nx = u.first + dx[i];
            int ny = u.second+ dy[i];
            int moves[] = {'U', 'D', 'L', 'R'};

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = 1;
                move[nx][ny] = moves[i];
                dis[nx][ny] = dis[u.first][u.second] + 1;
                parent[nx][ny] = {u.first, u.second};
                q.push({nx, ny});
            }
        }
    }

    if (dis[B.first][B.second] == 1e9) cout << "NO\n";
    else {
        cout << "YES\n" << dis[B.first][B.second] << endl;
        string path = "";
        pair<int, int> curr = B;
        while (curr != A) {
            path += move[curr.first][curr.second];
            curr = parent[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());
        cout << path << endl;
    }
}
 
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
 
    solve();
    return 0;
}
