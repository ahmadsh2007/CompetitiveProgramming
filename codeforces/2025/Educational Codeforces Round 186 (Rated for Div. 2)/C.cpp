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

int count(int n, const vector<int> &v1, const vector<int> &temp) {
    vector<int> v2 = temp;
    v2.insert(v2.end(), temp.begin(), temp.end());

    int cnt = 0;

    for (int s = 0; s < n; s++) {
        bool stable = true;
        for (int i = 0; i < n; i++)
            if (v1[i] >= v2[i + s]) { stable = 0; break; }
        if (stable) cnt++;
    }

    return cnt++;
}

void solve() {
    int n; cin >> n;
    vi(a, n) read(a)
    vi(b, n) read(b)
    vi(c, n) read(c)

    int ans = 0;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         for (int k = 0; k < n; k++) {
    //             bool stable = 1;
    //             int idx = 0;
    //             while (idx++ < n) if (c[(idx + k > n - 1 ? k - (n - idx) : k + idx)] <= b[(idx + j > n - 1 ? j - (n - idx) : j + idx)] || b[(idx + j > n - 1 ? j - (n - idx) : j + idx)] <= a[(idx + i > n - 1 ? i - (n - idx) : i + idx)]) { stable = 0; break; }
    //             if (stable) ans++;
    //         }
    //     }
    // }
    
    // cout << ans << endl;

    int shiftB = count(n, a, b);
    int shiftC = count(n, b, c);

    cout << shiftB * shiftC * n << endl;
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