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
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const char d[] = {'D', 'L', 'R', 'U'};
const int dx[] = {0, -1, 1, 0};
const int dy[] = {1, 0, 0, -1};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    vector<vector<int>> dist(n + 1, vector<int>(m + 1, -1)); 
    pair<int, int> start;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        cin >> grid[i][j];
        if (grid[i][j] == 'X') start.first = i, start.second = j;
    }
    if (k & 1) return void(cout << "IMPOSSIBLE\n");

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = u.first + dy[i];
            int nx = u.second + dx[i];
            if (ny < 1 or ny > n or nx < 1 or nx > m or dist[ny][nx] != -1 or grid[ny][nx] == '*') continue;

            dist[ny][nx] = dist[u.first][u.second] + 1;
            q.push({ny, nx});
        }
    }

    bool canMove = false;
    for (int i = 0; i < 4; ++i) {
        int ny = start.first + dy[i];
        int nx = start.second + dx[i];
        if (ny >= 1 && ny <= n && nx >= 1 && nx <= m && grid[ny][nx] != '*') canMove = true;
    }
    if (!canMove) return void(cout << "IMPOSSIBLE\n");

    str path = "";
    pair<int, int> cur = start;
    
    for (int step = 1; step <= k; ++step) {
        bool moved = false;
        for (int i = 0; i < 4; ++i) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            
            if (ny < 1 or ny > n or nx < 1 or nx > m or grid[ny][nx] == '*' or dist[ny][nx] == -1) continue;
            
            if (dist[ny][nx] <= k - step) {
                path += d[i];
                cur = {ny, nx};
                moved = true;
                break;
            }
        }
        if (!moved) return void(cout << "IMPOSSIBLE\n");
    }

    cout << path << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}