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
#define _vill1(a) vector<long long> a;
#define _vill2(a,n) vector<long long> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vill(...) GET_MACRO(__VA_ARGS__, _vill2, _vill1)(__VA_ARGS__)
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

const int N = 5001;
bool pali[N][N];

void solve() {
    str s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    
    for (int center = 0; center < n; center++) {
        int l = center, r = center;
        while (l >= 0 && r < n && s[l] == s[r]) {
            pali[l][r] = true;
            l--, r++;
        }
    }

    for (int center = 0; center + 1 < n; center++) {
        int l = center, r = center + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            pali[l][r] = true;
            l--, r++;
        }
    }

    while (q--) {
        int L, R; cin >> L >> R;
        L--, R--;
        cout << (pali[L][R] ? "YES\n" : "NO\n");
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
    #ifndef ONLINE_JUDGE
        // cin >> T;
    #endif
    while (T--) solve();
    return 0;
}