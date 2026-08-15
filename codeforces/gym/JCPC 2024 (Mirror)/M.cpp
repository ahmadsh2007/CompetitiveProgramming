#include <bits/stdc++.h>
using namespace std;
#define int long long
long long modpow(int a, int e, int mod = 1e9 + 7) {
    int r = 1;
    while (e) {
        if (e & 1) {
            r = r * a % mod;
        }
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> pairs(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end());
    int totalRings = 0;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            totalRings++;
            int target = pairs[i].first;
            vis[pairs[i].first] = true;
            int cur = pairs[i].second;
            while (target != cur) {
                vis[cur] = true;
                cur = pairs[cur].second;
            }
        }
    }

    cout << modpow(2, totalRings) - 1 << endl;
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