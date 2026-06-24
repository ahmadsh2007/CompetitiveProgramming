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

int MOD1 = -1, MOD2 = -1;
int P1 = -1, P2 = -1;

static const int init_hash_var = [](){
    int ms[] = {1000000007, 1000000009, 1000000021, 1000000033, 
                1000000087, 1000000093, 1000000097, 1000000103, 
                1000000123, 1000000181, 1000000207, 1000000223};
    MOD1 = ms[rnd(0, 11)];
    MOD2 = ms[rnd(0, 11)];
    while (MOD1 == MOD2) MOD2 = ms[rnd(0, 11)];

    // Deletable:
    // P doesn't have to be prime, but it has to be a co-prime with the MOD
    int bs[] = {307, 311, 313, 317, 331, 337,
                347, 349, 353, 359, 367, 373};
    P1 = bs[rnd(0, 11)];
    P2 = bs[rnd(0, 11)];
    while (P1 == P2) P2 = bs[rnd(0, 11)];

    return 0;
}();

struct PolyHash {
    vector<long long> hash1, hash2, power1, power2;
    string s;

    PolyHash(const string &ts) {
        s = ts;

        assert(MOD1 != -1 && MOD2 != -1);
        assert(P1 != -1 && P2 != -1);
        
        int n = (int) s.size();
        hash1.assign(n + 1, 0); hash2.assign(n + 1, 0);
        power1.assign(n + 1,1); power2.assign(n + 1,1);

        for (int i = 0; i < n; ++i) {
            hash1[i + 1] = (hash1[i] * P1 + s[i]) % MOD1;
            hash2[i + 1] = (hash2[i] * P2 + s[i]) % MOD2;
            power1[i + 1] = (power1[i] * P1) % MOD1;
            power2[i + 1] = (power2[i] * P2) % MOD2;
        }
    }

    pair<long long, long long> get_hash(int l, int r) {
        long long h1 = (hash1[r + 1] - (hash1[l] * power1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        long long h2 = (hash2[r + 1] - (hash2[l] * power2[r - l + 1]) % MOD2 + MOD2) % MOD2;
        return {h1, h2};
    }

    bool equal(PolyHash & o, int l1, int r1, int l2, int r2) {
        return r1 - l1 == r2 - l2 && get_hash(l1, r1) == o.get_hash(l2, r2);
    }

    bool less(PolyHash & o, int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        int maxLen = min(len1, len2);

        int l = 1, r = maxLen, ret = 0;        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (get_hash(l1, l1 + mid - 1) == o.get_hash(l2, l2 + mid - 1)) {
                ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (ret == maxLen) return len1 < len2;
        return s[l1 + ret] < o.s[l2 + ret]; 
    }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool check(int mid, const int & n, PolyHash & h) {
    auto target = h.get_hash(0, mid - 1);
    for (int i = 1; i <= n - mid - 1; ++i) {
        if (h.get_hash(i, i + mid - 1) == target) return true;
    }
    return false;
}

void solve() {
    str s; cin >> s;
    int n = (int) s.size();
    PolyHash h(s);
    
    vector<int> valid;
    for (int i = 1; i < n; ++i) {
        if (h.get_hash(0, i - 1) == h.get_hash(n - i, n - 1)) {
            valid.push_back(i);
        }
    }

    int ans = -1;
    int l = 0, r = (int) valid.size() - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(valid[mid], n, h)) {
            ans = valid[mid];
            l = mid + 1;
        } else r = mid - 1;
    }

    if (ans == -1) cout << "Just a legend\n";
    else cout << s.substr(0, ans) << endl;
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