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

const int MOD = 998244353;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

long long modpow(long long a,long long e,long long mod){long long r=1;while(e){if(e&1)r=r*a%mod;a=a*a%mod;e>>=1;}return r;}

long long modInverse(long long b) {
    return modpow(b, MOD - 2, MOD);
}

long long modDivide(long long a, long long b) {
    a %= MOD;
    return (a * modInverse(b)) % MOD;
}

void solve() {
    int n; cin >> n;
    
    vector<int> a(n); cin >> a;

    vi prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = (prefix[i] + a[i]) % MOD;
    }

    vi prefix2(n + 2, 0);
    for (int i = 1; i <= n + 1; ++i) prefix2[i] = (prefix2[i - 1] + prefix[i - 1]) % MOD;

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        int x = (prefix2[n + 1] - prefix2[i] + MOD) % MOD;
        int y = (prefix2[n - i + 1] - prefix2[0] + MOD) % MOD;
        int diff = (x - y + MOD) % MOD;
        int cur = modDivide(diff, i);
        ans = (ans + cur) % MOD;
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