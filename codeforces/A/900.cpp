#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n; cin >> n;
    int sides[4] = {0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (x < 0) {
            sides[0]++;
        }
        else if (x > 0) {
            sides[1]++;
        }

        if (y < 0) {
            sides[2]++;
        }
        else if (y > 0) {
            sides[3]++;
        }
    }

    bool can = true;
    if (sides[0] > 1 and sides[1] > 1) can = false;
    cout << (can ? "YES" : "NO") << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}