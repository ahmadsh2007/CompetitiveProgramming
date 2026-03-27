#include <bits/stdc++.h>
using namespace std;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, l; cin >> n >> m >> l;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> arms(m);
        int last = 0;
        for (int i = 0; i <= n; ++i) {
            int cur = (i < n ? a[i] : l);
            int x = cur - last;
            last = cur;

            int alive = min(m, n - i + 1);

            while (x--) {
                sort(arms.rbegin(), arms.rend());
                arms[alive - 1]++;
            }

            int mx = 0;
            int idx = 0;
            for (int j = 0; j < (int) arms.size(); ++j) {
                if (arms[j] > mx) {
                    mx = arms[j];
                    idx = j;
                }
            }
            if (i < n) arms[idx] = 0;
        }

        int ans = 0;
        for (int i = 0; i < (int) arms.size(); ++i) ans = max(ans, arms[i]);
        cout << ans << endl;
    }
}