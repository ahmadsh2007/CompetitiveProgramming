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

void answer(int n, str a) {
    vi ans(n);
    int l = 0, r = n - 1;
    while (a[l] != '(') l++;
    while (a[r] != ')') r--;

    bool one = 0;
    while (l < r) {
        if (a[l] == '(' && a[r] == ')') {
            ans[l] = ans[r] = 1;
            l++, r--;
            one = 1;
        }
        else {
            if (a[l] == ')') l++;
            if (a[r] == '(') r--;
        }
    }

    bool two = 0;
    if (one) {
        for (int i = 0; i < n; i++) if (ans[i] == 0) two = 1, ans[i] = 2;
    }
    else {
        for (int i = 0; i < n; i++) if (ans[i] == 0) ans[i] = 1;
    }

    cout << (two ? "2\n" : "1\n");
    cout << ans << endl;
}

void solve() {
    int n; cin >> n;
    str a; cin >> a;
    
    int open = 0, close = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '(') open++;
        else close++;
    }

    if (open != close) { cout << "-1\n"; return; }

    open = 0, close = 0;
    bool reverse = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '(') open++;
        if (a[i] == ')') close++;

        if (close > open) {
            reverse = 1;
            break;
        }
    }

    bool check = 0;
    str a2;
    for (int i = 0; i < n; i++) if (a[i] == '(') a2 += ')'; else a2 += '(';
    open = 0, close = 0;
    if (reverse)
    for (int i = 0; i < n; i++) {
        if (a2[i] == '(') open++;
        if (a2[i] == ')') close++;

        if (close > open) {
            check = 1;
            break;
        }
    }

    if (check) answer(n, a);
    else {
        cout << "1\n";
        for (int i = 0; i < n; i++) cout << 1 << " \n"[i == n - 1];
    }
}

const int TESTCASES = 1;
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