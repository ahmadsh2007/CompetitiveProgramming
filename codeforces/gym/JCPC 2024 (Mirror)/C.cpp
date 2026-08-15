#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int a, n; cin >> a >> n;
    if (a * (n / a) == (a * n) / a) cout << "Yes\n";
    else cout << "No\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}