#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
    
        int ans = 0;
        int cur = 0;
        int zeroCnt = 0;
        int target = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                cur++;
                zeroCnt++;
            }
            else if (target = 0 or a[i] == target) {
                target = a[i];
                cur++;
                zeroCnt = 0;
            }
            else {
                cur = zeroCnt + 1;
                target = a[i];
                zeroCnt = 0;
            }
            ans = max(ans, cur);
        }
    
        cout << ans << endl;
    }

    return 0;
}