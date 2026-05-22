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

long long modpow(long long a,long long e,long long mod){long long r=1;while(e){if(e&1)r=r*a%mod;a=a*a%mod;e>>=1;}return r;}

void solve() {
    int a, b, c; cin >> a >> b >> c;

    int mod = 1e9 + 7;

    cout << modpow(a, modpow(b, c, mod - 1), mod) << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int t; cin >> t;
    while (t--) solve();
    return 0;
}