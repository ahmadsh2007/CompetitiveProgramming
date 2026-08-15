// WA26
#include <bits/stdc++.h>
using namespace std;
#define int long long
//__builtin_ctzll(n)
int fact(int n) {
    int r = 1;
    for (int i = 2; i <= n; ++i) r *= i;
    return r;
}
void solve() {
    int a, b, x; cin >> a >> b >> x;

    if ((a & b) >= x) {
        return void(cout << 0 << endl);
    }

    vector<int> opt;
    int mn = 100;
    for (int bit = 30; bit >= 0; --bit) {
        int cur = 0;
        vector<int> curr;
        int y = a, z = b;
        for (int j = bit; j >= 0; --j) {
            int used = 0;
            if (!((1ll << j) & y)) {
                cur++;
                curr.push_back(j);
                used = 1;
                y |= (1ll << j);
            }
            if (!((1ll << j) & z)) {
                cur++;
                if (!used) curr.push_back(j);
                z |= (1ll << j);
            }
            if ((y & z) >= x) {
                if (cur < mn) {
                    mn = cur;
                    opt = curr;
                }
            }
        }
    }

    cout << mn << '\n';
    for (int i = 0; i < (int) opt.size(); ++i) {
        if (!((1ll << opt[i]) & a)) {
            cout << "a " << opt[i] << '\n';
        }
        if (!((1ll << opt[i]) & b)) {
            cout << "b " << opt[i] << '\n';
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}