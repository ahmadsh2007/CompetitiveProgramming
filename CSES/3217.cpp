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

const int dx[] = {2, 1, -2, -1, 2, 1, -2, -1};
const int dy[] = {1, 2, -1, -2, -1, -2, 1, 2};

void solve() {
    int n; cin >> n;
    int grid[n][n];
    bool vis[n][n];
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) grid[i][j] = 1e6;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) vis[i][j] = 0;

    queue<pair<int, int>> q;
    grid[0][0] = 0;
    vis[0][0] = 1;
    q.push({0, 0});
    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        
        for (int i = 0; i < 8; ++i) {
            pair<int, int> v = {u.first + dx[i], u.second + dy[i]};
            if (v.first < 0 or v.first >= n or
                v.second < 0 or v.second >= n or
                vis[v.first][v.second]) continue;
            
            q.push(v);
            vis[v.first][v.second] = 1;
            grid[v.first][v.second] = grid[u.first][u.second] + 1;
        }
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cout << grid[i][j] << " \n"[j == n - 1];
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}