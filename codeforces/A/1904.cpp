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
    int a, b; cin >> a >> b;
    int kx, ky; cin >> kx >> ky;
    int qx, qy; cin >> qx >> qy;

    set<pair<int, int>> p1, p2;
    int x[] = {-1, 1, -1, 1};
    int y[] = {-1, -1, 1, 1};
    for (int i = 0; i < 4; i++) {
        p1.insert({kx + x[i] * a, ky + y[i] * b});
        p2.insert({qx + x[i] * a, qy + y[i] * b});
        p1.insert({kx + x[i] * b, ky + y[i] * a});
        p2.insert({qx + x[i] * b, qy + y[i] * a});
    }

    int ans = 0;
    for (auto x : p1)
        if (p2.find(x) != p2.end()) ans += 1;
    cout << ans << '\n';
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}