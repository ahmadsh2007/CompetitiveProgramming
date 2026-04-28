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
    int n, k; cin >> n >> k;
    vi(a, n) read(a)
    
    int mx = 0, L = 0, R = 0;
    int l = 0, r = 0;
    map<int, int> m;
    int diff = 0, cur = 0;
    while (l < n && r < n) {
        m[a[r]]++;
        cur++;
        if (m[a[r]] == 1) diff++;
        while (k < diff) {
            m[a[l]]--;
            if (m[a[l]] == 0) diff--;
            cur--, l++;
        }
        if (cur > mx) mx = cur, L = l, R = r;
        r++;
    }

    cout << L + 1 << ' ' << R + 1 << endl; 
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
    // cin >> T;
    while (T--) solve();
    return 0;
}