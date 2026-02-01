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

bool check(str x) {
    int l = 0, r = x.size() - 1;
    bool pali = 1;
    while (l <= r) {
        if (x[l] != x[r]) { pali = 0; break; }
        l++, r--;
    }

    return pali;
}

void solve() {
    int n, k; cin >> n >> k;
    str s; cin >> s;

    str s1 = s, s2 = s;
    s1.erase(0, k);
    s2.erase(n - k, k);
    if (check(s1) || check(s2)) { cout << "1\n"; return; }

    str s3 = s, s4 = s;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (s[l] == s[r]) l++, r--;
        else break;
    }
    if (l < r) {
        s3.erase(l, k);
        s4.erase(r + 1 - k, k);
        if (check(s3) || check(s4)) { cout << "1\n"; return; }
    }

    int it = (n - k) / 2;
    l = 0, r = n - 1;
    int ans = 1;
    while (l < it) {
        if (s[l] != s[r]) { ans = 0; break; }
        l++, r--;
    }

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