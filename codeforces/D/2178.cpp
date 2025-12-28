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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;

    if (n / 2 < m) { cout << -1 << endl; return; }
    
    sort(all(a));

    if (m == 0) {
        int sum = 0;
        for (int i = 0; i < n - 1; i++) sum += a[i].first;
        if (sum < a[n - 1].first) { cout << -1 << endl; return; }
        cout << n - 1 << endl;
        int health = a[n - 1].first;
        int idx = n - 2;
        while (a[idx].first < health && idx) {
            cout << a[idx].second << ' ' << a[n - 1].second << '\n';
            health -= a[idx].first;
            idx--;
        }
        for (int i = 1; i <= idx; i++) cout << a[i - 1].second << ' ' << a[i].second << endl;
        cout << a[n - 1].second << ' ' << a[idx].second << endl;
        return;
    }
    if (m == 1) {
        cout << n - 1 << endl;
        for (int i = 0; i < n - 2; i++)
            cout << a[i].second << ' ' << a[i + 1].second << endl;

        cout << a[n - 1].second << ' ' << a[n - 2].second << endl;
        return;
    }
    cout << n - m << endl;
    int idx = n - 1, midx = n - 2;
    int moveTo = n - m * 2;
    while(--m) {
        cout << a[idx].second << ' ' << a[midx].second << endl;
        idx -= 2, midx -= 2;
    }
    for (int i = 1; i <= moveTo; i++) cout << a[i - 1].second << ' ' << a[i].second << '\n';
    cout << a[moveTo + 1].second << ' ' << a[moveTo].second << endl;
    return;
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