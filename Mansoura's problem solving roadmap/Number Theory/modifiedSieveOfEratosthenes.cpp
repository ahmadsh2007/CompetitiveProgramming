/*
Algorithm: Sieve of Eratosthenes with Smallest Prime Factor (SPF)

Idea:
- Precompute the smallest prime factor (SPF) for every number up to N
- For each prime i, mark i as its own SPF
- For every multiple j of i, if SPF[j] is not set, assign SPF[j] = i

Usage:
- Enables fast prime factorization of any number x ≤ N
- Factorization is done by repeatedly dividing x by SPF[x]

Time Complexity:
- Preprocessing: O(N log log N)
- Each prime factorization query: O(log N)

Space Complexity:
- O(N)

Commonly used in competitive programming for handling many
prime factorization queries efficiently.
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

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 1500000;
vector<bool> primes(N + 1, 1);
vector<int> divide(N + 1);

vi primeFactorization(int n) {
    vi ret;
    while (n != 1) {
        ret.push_back(divide[n]);
        n /= divide[n];
    }

    return ret;
}

void solve() {
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        vi ans = primeFactorization(x);
        cout << ans << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    primes[0] = primes[1] =0;
    for (int i = 2; i <= N; i++) {
        if (primes[i]) {
            divide[i] = i;
            for (int j = i * i; j <= N; j += i) {
                primes[j] = 0;
                if (divide[j] == 0) divide[j] = i;
            }
        }
    }

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}