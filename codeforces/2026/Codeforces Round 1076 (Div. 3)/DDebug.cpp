#include <bits/stdc++.h>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "../Utils/debug.h"
// #endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define _vi1(a) vector<int> a;
#define _vi2(a,n) vector<int> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vi(...) GET_MACRO(__VA_ARGS__, _vi2, _vi1)(__VA_ARGS__)
#define _vill1(a) vector<long long> a;
#define _vill2(a,n) vector<long long> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vill(...) GET_MACRO(__VA_ARGS__, _vill2, _vill1)(__VA_ARGS__)
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using i64 = long long;
using ll  = long long;
using u64 = unsigned long long;
using ull = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n = 6;
    vi(a, n)
    a = {4, 4, 1, 4, 5, 4};

    vector<int> remove = {2, 2, 4, 1, 2, 2};
    vector<int> pre(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int b = remove[i];
        sum += b;
        pre[i] = sum;
    }
    remove.clear();

    sort(rall(a));

    int ans = 0;
    int i = 0;
    while (i < n) {
        int x = a[i];
        int m = i;
        while (m < n && a[m] == x) m++;

        int k = upper_bound(all(pre), m) - pre.begin();
        ans = max(ans, x * k);

        i = m;
    }

    cout << ans << endl;    
}

signed main() {
    // #ifndef ONLINE_JUDGE
    // #if __has_include("../../Utils/debug.h")
    //   freopen("../../Utils/input.txt", "r", stdin);
    //   freopen("../../Utils/output.txt", "w", stdout);
    // #else
    //   freopen("../../../Utils/input.txt", "r", stdin);
    //   freopen("../../../Utils/output.txt", "w", stdout);
    // #endif
    // #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}