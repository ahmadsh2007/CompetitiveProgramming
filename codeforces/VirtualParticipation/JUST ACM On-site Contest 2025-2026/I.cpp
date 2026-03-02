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

void solve() {
    int n; cin >> n;
    vector<int> prefix(n + 1);
    vector<int> suffix(n + 1);
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cur = a[0];
    for (int i = 1; i < n; i++) {
        cur = max(cur, a[i]);
        prefix[i] = prefix[i - 1] + (cur - a[i]);
    }

    cur = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        cur = max(cur, a[i]);
        suffix[i] = suffix[i + 1] + (cur - a[i]);
    }

    int ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, prefix[i] + suffix[i]);
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