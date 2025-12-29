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
    int n, m, k; cin >> n >> m >> k;

    if (n == 0 || m == 0) if (n == k || m == k) {
        if (n) for (int i = 0; i < n; i++) cout << 0;
        else for (int i = 0; i < m; i++) cout << 1;
        cout << '\n';
        return;
    } else { cout << -1 << endl; return; }

    if (abs(n - m) > k || (k > n && k > m)) { cout << -1 << '\n'; return; }

    if (n > m) {
        for (int i = 0; i < k; i++) cout << 0;
        for (int i = 0; i < n - k; i++) cout << 10;
        for (int i = 0; i < m - n + k; i++) cout << 1;
        cout << endl;
    } else {
        for (int i = 0; i < k; i++) cout << 1;
        for (int i = 0; i < m - k; i++) cout << "01";
        for (int i = 0; i < n - m + k; i++) cout << 0;
        cout << endl;
    }
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
    cin >> T;
    while (T--) solve();
    return 0;
}