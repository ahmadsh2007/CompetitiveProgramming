#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../Utils/debug.h"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
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

int sum(vector<int> &a, vector<int> &b, vector<int> &c) {
    int n = a.size();
    int mxA = 0, mxB = 0, mxC = 0;
    int ia = 0, ib = 0, ic = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mxA) mxA = a[i], ia = i;
    }
    for (int i = 0; i < n; i++) {
        if (b[i] > mxB && i != ia) mxB = b[i], ib = i; 
    }
    for (int i = 0; i < n; i++) {
        if (c[i] > mxC && i != ia && i != ib) mxC = c[i], ic = i;
    }

    return mxA + mxB + mxC;
}

void solve() {
    // Another way can be done is to find the maximum 3 numbers in each array and try all combinations (3 ^ 3) to find the maximum answer
    int n; cin >> n;
    vi a(n), b(n), c(n);
    cin(a) cin(b) cin(c)
    
    int ans = 0;
    ans = max({sum(a, b, c), sum(a, c, b), sum(b, a, c), sum(b, c, a), sum(c, a, b), sum(c, b, a)});

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

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