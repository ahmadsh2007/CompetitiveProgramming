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

const int N = 1e6;
vector<int> primes, spf(N+1);
static const int PrimesAndSPF=[](){
    for(int i=2;i<=N;i++){ if(!spf[i]) spf[i]=i,primes.push_back(i); for(int p:primes){ if(1LL*p*i>N) break; spf[p*i]=p; if(p==spf[i]) break; } } return 0;
}();

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    bool allOnes = 1;
    for (int i = 0; i < n; ++i) if (a[i] != 1) allOnes = 0;
    if (allOnes) return void(cout << "1\n");

    map<int, vector<int>> freq;
    auto primeCalculator = [&](int x) -> map<int, int> {
        map<int, int> divisors;
        while (x != 1) {
            divisors[spf[x]]++;
            x /= spf[x];
        }
        return divisors;
    };

    for (int i = 0; i < n; ++i) {
        map<int, int> cur = primeCalculator(a[i]);
        for (auto &[key, cnt] : cur) {
            freq[key].push_back(cnt);
        }
    }

    int ans = 1;
    for (auto &[key, cnt] : freq) {
        if ((int) cnt.size() < n - 1) continue;
        sort(all(cnt));

        int power;
        if ((int) cnt.size() == n) power = cnt[1];
        else power = cnt[0];
        
        ans *= binpow(key, power);
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