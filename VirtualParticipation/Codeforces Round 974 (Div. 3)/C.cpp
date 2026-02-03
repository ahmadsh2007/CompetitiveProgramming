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

bool spawned(vector<int> & a, int n, int x, int sum) {
    int unhappy = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < (sum + x) * 1.0 / n / 2) unhappy++;
    }

    return unhappy > n / 2;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin(a);
    if (n < 3) { cout << "-1\n"; return; }

    int sum = accumulate(all(a), 0LL);
    int l = 0, r = 1e18, mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (spawned(a, n, mid, sum)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << max(0LL, ans) << endl;
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