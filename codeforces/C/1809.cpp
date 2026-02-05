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

vector<int> solve(int n, int k) {
    // int n, k; cin >> n >> k;
    // vi a(n, -1);
    // if (k == 0) {cout(a) cout << endl; return; }
    // if (k < n) {
    //     a[k - 1] = 999;
    //     a[k] = -1000;
    // }
    // else if (k == n) {
    //     a[0] = 1000;
    // }
    // else {
    //     for (int i = 0; i < n; i++) a[i] = -1000;
    //     int st = 0;
    //     while (k > 0) {
    //         int i = 0;
    //         int sum = 0;
    //         while (sum <= k) {
    //             i++;
    //             sum = i * (i + 1) / 2;
    //         }
    //         i--;
    //         sum = i * (i + 1) / 2;
    //         for (int x = 0; x < i && st + x < n; x++) a[x + st] = 1;
    //         st = i;
    //         k -= sum;
    //     }
    // }
    vi a;
    if (n == 0) return {}; 
    if (k < n) {
        for (int i = 0; i < n; i++) a.push_back(-1);
        if (k > 0) a[k - 1] = 200;
        a[k] = -400;
    }
    else {
        a = solve(n - 1, k - n);
        a.push_back(1000);
    }

    return a;
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
    while (TTT--) {
        int n, k; cin >> n >> k;
        vi a;
        a = solve(n, k);

        cout(a) cout << endl;
    }
    return 0;
}