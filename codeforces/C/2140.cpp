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
    vi a(n); cin(a)

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2) ans -= a[i];
        else ans += a[i];
    }

    int initiate = ans;
    for (int i = 0; i < n; i++) ans = max(ans, initiate + i - (i % 2));

    int minEve = LLONG_MAX / 2, minOdd = LLONG_MAX / 2;
    for (int i = 0; i < n ; i++) {
        if (i % 2) {
            ans = max(initiate + i + 2 * a[i] - minEve, ans);
            minOdd = min(minOdd, i - 2 * a[i]);
        }
        else {
            ans = max(initiate + i - 2 * a[i] - minOdd, ans);
            minEve = min(minEve, i + 2 * a[i]);
        }
    }

    cout << ans << '\n';
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