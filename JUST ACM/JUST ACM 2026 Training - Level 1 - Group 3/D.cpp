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

int ret(int n, string op, vector<int> & a, int idx, int sum, int changes) {
    if (idx == n)
        return (sum == 0 ? changes : 100);

    int res = 100;
    res = min(res, ret(n, op, a, idx + 1, sum + a[idx], changes + (op[idx] != '+')));
    res = min(res, ret(n, op, a, idx + 1, sum - a[idx], changes + (op[idx] != '-')));

    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<char> ops(n - 1);
    
    cin >> a[0];
    for (int i = 1; i < n; ++i) cin >> ops[i - 1] >> a[i];
    string op = "+";
    for (auto o : ops) op += o;
    
    // cout << c << endl << a << endl << op << endl;

    int ans = ret(n, op, a, 1, a[0], 0);
    cout << (ans == 100 ? -1 : ans) << endl;
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