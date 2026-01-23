#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

#define endl '\n'
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    int a[n];
    int mx = -1e9;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != mx) cur = 0;
        else cur++;

        ans += cur;
    }

    cout << ans << endl;
}

signed main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}