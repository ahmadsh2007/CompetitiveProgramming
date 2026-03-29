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

int solver(int n, str s) {
    int L = 0;
    int P = n;
    int balance = 0;
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') balance++;
        else balance--;
        
        if (i < n - 1) {
            if (s[i] == '(' && s[i+1] == ')') L++;
            
            if (s[i] == ')' && s[i+1] == '(') P = min(P, balance);
        }
    }
    

    // To make sure it's impossible to have the same value from different L and P
    int ret = L * 1e6 + P;
    return ret;
}

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    str t; cin >> t;


    int ans = solver(n, s) == solver(n, t);

    cout << (ans ? "YES\n" : "NO\n");
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    while (TTT--) solve();
    return 0;
}