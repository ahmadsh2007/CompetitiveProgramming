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

#define _vi1(a) vector<int> a;
#define _vi2(a,n) vector<int> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vi(...) GET_MACRO(__VA_ARGS__, _vi2, _vi1)(__VA_ARGS__)
#define read(v) for (auto &x : v) cin >> x;

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
    int x, y, m; cin >> x >> y >> m;

    if (x >= m || y >= m) { cout << 0 << endl; return; }
    if (x <= 0 && y <= 0) { cout << -1 << endl; return; }

    int ans = 0;
    while (x < m && y < m) {
        int a = min(x, y);
        int b = max(x, y);

        if (b <= 0) {
            cout << -1 << endl;
            return;
        }

        if (a < 0) {
            int temp = ((-a) + b - 1) / b;
            a += temp * b;
            ans += temp;
        } else a = a + b, ans++;

        x = a, y = b;
    }
    cout << ans << endl;
}

#undef int
int main() {
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

    ull T = 1;
    #ifndef ONLINE_JUDGE
        cin >> T;
    #endif
    while (T--) solve();
    return 0;
}