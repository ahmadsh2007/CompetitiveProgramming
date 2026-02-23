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

const int N = 6e6 + 1;
vector<bool> isPrime;
vector<int> primes;
vector<int> primesPrefix;

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    sort(rall(a));
    int ans = 0;
    int sumOriginal = 0, sumPrimes = 0;
    for (int i = 0; i < n; i++) {
        sumOriginal += a[i];
        sumPrimes += primes[i];
        if (sumOriginal >= sumPrimes) ans = i + 1;
    }

    cout << n - ans << endl;
}

vector<bool> sieve(int n){vector<bool> p(n+1,true);if(n>=0)p[0]=0;if(n>=1)p[1]=0;for(int i=2;i*i<=n;i++)if(p[i])for(int j=i*i;j<=n;j+=i)p[j]=0;return p;}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    isPrime = sieve(N);
    for (int i = 2; i <= N; i++) if (isPrime[i]) primes.push_back(i);
    primesPrefix.push_back(0);
    for (int i = 0; i < primes.size(); i++) primesPrefix.push_back(primesPrefix[i] + primes[i] - 2);

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