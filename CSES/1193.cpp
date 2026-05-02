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

        if (u.first != 0) {
            if (!visited[u.first - 1][u.second] && dis[u.first - 1][u.second] == 1e9 && grid[u.first - 1][u.second] != '#') {
                visited[u.first - 1][u.second] = 1;
                move[u.first - 1][u.second] = 'U';
                dis[u.first - 1][u.second] = dis[u.first][u.second] + 1;
                parent[u.first - 1][u.second] = {u.first, u.second};
                q.push({u.first - 1, u.second});
            } 
        }
        if (u.first != n - 1) {
            if (!visited[u.first + 1][u.second] && dis[u.first + 1][u.second] == 1e9 && grid[u.first + 1][u.second] != '#') {
                visited[u.first + 1][u.second] = 1;
                move[u.first + 1][u.second] = 'D';
                dis[u.first + 1][u.second] = dis[u.first][u.second] + 1;
                parent[u.first + 1][u.second] = {u.first, u.second};
                q.push({u.first + 1, u.second});
            } 
        }
        if (u.second != 0) {
            if (!visited[u.first][u.second - 1] && dis[u.first][u.second - 1] == 1e9 && grid[u.first][u.second - 1] != '#') {
                visited[u.first][u.second - 1] = 1;
                move[u.first][u.second - 1] = 'L';
                dis[u.first][u.second - 1] = dis[u.first][u.second] + 1;
                parent[u.first][u.second - 1] = {u.first, u.second};
                q.push({u.first, u.second - 1});
            } 
        }
        if (u.second != m - 1) {
            if (!visited[u.first][u.second + 1] && dis[u.first][u.second + 1] == 1e9 && grid[u.first][u.second + 1] != '#') {
                visited[u.first][u.second + 1] = 1;
                move[u.first][u.second + 1] = 'R';
                dis[u.first][u.second + 1] = dis[u.first][u.second] + 1;
                parent[u.first][u.second + 1] = {u.first, u.second};
                q.push({u.first, u.second + 1});
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
