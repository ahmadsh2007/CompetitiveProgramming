#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define str string

void solve() {
    int l, r, x; cin >> l >> r >> x;
    int ans = 0;
    
    for (int i = 0; i < 31; ++i) {
        int cur = 0;
        for (int j = i + 1; j < 31; ++j) {
            cur |= (1 << j);
            if (cur <= x) {
                
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}