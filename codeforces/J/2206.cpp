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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n, d; cin >> n >> d;
    
    vi a(n), posA(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        posA[a[i]] = i;
    }
    vi b(n), posB(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        posB[b[i]] = i;
    }

    auto checkLoop = [&](int i) -> bool {
        if (i < 0 || i >= n - 1) return false;
        return posA[b[i + 1]] < posA[b[i]];
    };

    int loops = 0;
    for (int i = 0; i < n - 1; ++i) loops += checkLoop(i);

    cout << loops * n + posA[b[n - 1]] + 1 - n << endl;

    while (--d) {
        int c, x, y; cin >> c >> x >> y;
        x--, y--;

        if (c == 1) {
            int s1 = a[x], s2 = a[y];
            int i1 = posB[s1], i2 = posB[s2];

            set<int> affectedInd;
            affectedInd.insert(i1 - 1);
            affectedInd.insert(i1);
            affectedInd.insert(i2 - 1);
            affectedInd.insert(i2);

            for (int idx : affectedInd) {
                loops -= checkLoop(idx);
            }

            swap(a[x], a[y]);
            swap(posA[s1], posA[s2]);

            for (int idx : affectedInd) {
                loops += checkLoop(idx);
            }
        }
        else {
            set<int> affectedInd;
            affectedInd.insert(x - 1);
            affectedInd.insert(x);
            affectedInd.insert(y - 1);
            affectedInd.insert(y);

            for (int idx : affectedInd) {
                loops -= checkLoop(idx);
            }

            int s1 = b[x], s2 = b[y];
            swap(b[x], b[y]);
            swap(posB[s1], posB[s2]);

            for (int idx : affectedInd) {
                loops += checkLoop(idx);
            }
        }

        cout << loops * n + posA[b[n - 1]] + 1 - n << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef LOCAL
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}