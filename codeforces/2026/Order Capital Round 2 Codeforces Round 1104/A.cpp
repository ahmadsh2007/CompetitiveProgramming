#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        for (int i = 1; i < n; ++i) if (a[i] > a[i - 1]) a[i] = a[i - 1];
        int ans = accumulate(a.begin(), a.end(), 0ll);
        cout << ans << endl;
    }
}