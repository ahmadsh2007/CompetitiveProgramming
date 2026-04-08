//
// Created by Leeking on 4/8/26.
//

#include <bits/stdc++.h>

using namespace std;

#define int long long

static const int SPEED_UP = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int mx = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            mx = max(mx, a[i - 1] - a[i]);
            a[i] = a[i - 1];
        }
    }

    int ans = 0;
    if (mx > 0) ans = log2(mx) + 1;
    cout << ans << endl;
}

signed main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}