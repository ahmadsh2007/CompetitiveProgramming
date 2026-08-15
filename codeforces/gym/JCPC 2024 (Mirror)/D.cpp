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
    int q; cin >> q;

    auto calc = [](int x) -> int {    
        int total = 0;
        for (int p = 5; p <= x; p *= 5) {
            int q = x / p;
            int rem = x % p;
            total += p * (q * (q - 1) / 2) + q * (rem + 1);
            
            if (p > x / 5) break;
        }
        return total;
    };
    while (q--) {
        int l, r; cin >> l >> r;
        cout << calc(r) - calc(l - 1) << endl;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}