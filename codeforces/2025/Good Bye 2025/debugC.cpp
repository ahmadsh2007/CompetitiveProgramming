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
#define read(v) for (auto &x : v) cin >> x;

using i64 = long long;
using ll = long long;
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
    int n = 5;
    vi(a, n) 
    a = {7, -6, -1, -8, -8};
    
    // int l = 0, r = 1;
    // int re = a.size();
    // int ans = 0;
    
    // if (re == 2) {
    //     if (a[l] > -a[r]) { cout << a[l] << endl; return; }
    //     else cout << -a[r] << endl;
    //     return;
    // }
    
    // while (re != 1) {
    //     if (a[l] < 0 && a[r] > 0) {
    //         int sum = 0;
    //         int rr = r;
    //         while(true && rr < re) {
    //             if (a[rr] < 0) sum -= a[rr], r++;
    //             else break;
    //         }
    //         if (a[l] > sum) ans -= a[r], r++;
    //         else ans += a[l], l = r, r++;
    //     }
    //     else if (a[l] > 0 && a[r] < 0){
    //         if (a[l] > -a[r]) ans += a[l], l = r, r++;
    //         else ans -= a[r], r++;
    //     }
    //     else if (a[l] < 0 && a[r] < 0) {
    //         ans -= a[r] , r++;
    //     } else ans += a[l], l = r, r++;
    //     re--;
    // }
    
    // cout << ans << endl;

    // ! Lemme redo it
    int ans = 0;
    int mx = a[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans - a[i], mx);

        if (a[i] < 0) mx -= a[i];
        else mx += a[i];
    }

    cout << ans << endl;
}

#undef int
int main() {
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