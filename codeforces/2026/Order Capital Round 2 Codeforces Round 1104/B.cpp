#include <bits/stdc++.h>
using namespace std;
#define int long long
void bubble(vector<int>&a,int&ans) {
    int n = (int) a.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                ans++;
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;
        vector<int> p(n);
        vector<int> v(n);
        bool flag = 1;
        for (int i = 0; i < n; ++i) {
            int idx = -1;
            for (int j = 0; j < n; ++j) {
                if (!v[j] && a[j] <= b[i]) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                flag = 0;
                break;
            }
            v[idx] = 1;
            p[idx] = i;
        }
        if (!flag) cout << "-1\n";
        else {
            int ans = 0;
            bubble(p, ans);
            cout << ans << endl;
        }
    }
}