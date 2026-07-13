/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // Generates a random seed once per program execution
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    // Safe O(1) Map
    // std::unordered_map<long long, int, custom_hash> safe_map;
    // Safe O(1) Set
    // std::unordered_set<long long, custom_hash> safe_set;
    // Fastest, safest map for CP
    // gp_hash_table<long long, int, custom_hash> fast_safe_map;
};

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

// Macro to generate a random integer between l and r (inclusive)
// To use: `ll my_random_number = rnd(1, 100);` or `int random_index = rnd(0, my_vector.size() - 1);`
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<ll>(l, r)(rng)

int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

struct Point {
    int y;
    int x;

    bool operator<(const Point& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }
};

void solve() {
    Point start, finish; cin >> start.y >> start.x >> finish.y >> finish.x;
    int n; cin >> n;
    gp_hash_table<long long, int, custom_hash> dist;
    gp_hash_table<long long, bool, custom_hash> adj;
    gp_hash_table<long long, bool, custom_hash> vis;
    Point cur;
    for (int i = 1; i <= n; ++i) {
        int r, l, rr; cin >> r >> l >> rr;
        for (int x = l; x <= rr; ++x) {
            cur.y = r;
            cur.x = x;
            adj[cur.y * 1000000000LL + cur.x] = 1;
        }
    }
    
    queue<Point> q;
    vis[start.y * 1000000000LL + start.x] = 1;
    q.push(start);
    dist[start.y * 1000000000LL + start.x] = 0;
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        for (int k = 0; k < 8; ++k) {
            int ny = u.y + dy[k];
            int nx = u.x + dx[k];
            cur.y = ny;
            cur.x = nx;
            if (nx < 1 or nx > 1e9 or ny < 1 or ny > 1e9 or adj[cur.y * 1000000000LL + cur.x] == 0 or vis[cur.y * 1000000000LL + cur.x]) continue;
            
            q.push(cur);
            vis[cur.y * 1000000000LL + cur.x] = 1;
            dist[cur.y * 1000000000LL + cur.x] = dist[u.y * 1000000000LL + u.x] + 1;
        }
    }

    cur.y = finish.y;
    cur.x = finish.x;
    cout << (dist[cur.y * 1000000000LL + cur.x] ? dist[cur.y * 1000000000LL + cur.x] : -1) << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}