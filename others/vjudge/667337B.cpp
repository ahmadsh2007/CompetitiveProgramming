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

long long modpow(long long a,long long e,long long mod){
    long long r=1;
    while(e){
        if(e&1) r=r*a%mod;
        a=a*a%mod;
        e>>=1;
    }
    return r;
}

void solve() {
    // Given two integers `A` and `B`, your task is to compute the result of `A` % `B` (the remainder when `A` is divided by `B`).
    // Input
    // The first and only line of input contains two integers `A` and `B` (1 <= `A` <= 10 ^ (10 ^ 5), 1 <= `B` <= 10 ^ 9)
    // Output
    // Output a single integer, the remainder of `A` divided by `B` (i.e., `A` % `B`).
    // Examples
    // Input        Output
    // 5000 3       2
    // 54321 2      1

    
    // freopen("./667337B_helped/10_to_the_10_to_the_5.txt", "r", stdin);
    str s; cin >> s;
    int b; cin >> b;
    int ans = 0, ePwr = 1;
    reverse(all(s));
    for (int i = 0; i < s.size(); i++) {
        int digit = s[i] - '0';
        ans += digit % b;
        ans %= b;
        ePwr *= 10 % b;
        ePwr %= b;
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

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