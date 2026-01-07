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

// const int N = 5e5;
// vi(pre, N);
// int drawer = 1266;

// void solve() {
//     int n, l, r; cin >> n >> l >> r;
//     l--, r--;
//     // x * (x + 1) / 2 = 4e5
//     // x ^ 2 + x = 8e5
//     // x ^ 2 + x - 8e5 = 0
//     // (x + )(x - ) = 0
//     // ∆ = b ^ 2 - 4 * a * c = 1 + 16e5
//     // x = (-b (+-) √∆) / 2 ≈ 1265

//     vector<int> a{pre.begin(), pre.end()};
    
//     // for (int i = 0; i < n; i++) {
//     //     int sum = a[i];
//     //     for (int j = i + 1; j < n; j++) {
//     //         sum ^= a[j];
//     //     }
//     //     cout << sum << endl;
//     // }
//     // cout << endl;

//     a[l] = 1 << 11; // bigger than drawer
//     int temp = 0;
//     for (int i = l; i < r; i++) temp ^= a[i];
//     a[r] = temp;

//     for (int i = 0; i < n; i++) cout << a[i] << ' ';
//     cout << endl;
// }

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vi(a, n + 1);

    int cur = 0;
    for (int i = 0; i <= n; i++) {
        if (i == r) continue;
        a[i] = cur++;
    }
    a[r] = a[l - 1];

    for (int i = 1; i <= n; i++) {
        cout << (a[i] ^ a[i - 1]) << " ";
    }
    cout << '\n';
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

    // for (int i = 1; i < N; i++) {
    //     for (int j = 0; j < drawer; j++)
    //         pre[i - 1] = j;
    //     drawer--;
    // }

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}