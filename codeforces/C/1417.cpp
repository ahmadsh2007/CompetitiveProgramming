//
// Created by Leeking on 4/4/2026.
//

#include <bits/stdc++.h>

using namespace std;

static const int SPEED = []() -> int {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<vector<int>> p(n + 1);
        for (int i = 0; i < n; ++i) p[a[i]].push_back(i);

        vector<int> ans(n, -1);
        for (int i = 1; i <= n; ++i) {
            if (p[i].empty()) continue;

            int mx = p[i][0] + 1;
            for (int j = 1; j < (int) p[i].size(); ++j) mx = max(mx, p[i][j] - p[i][j - 1]);
            mx = max(mx, n - p[i].back());

            for (int j = mx - 1; j < n; ++j) {
                if (ans[j] != -1) break;
                ans[j] = i;
            }
        }

        for (int i = 0; i < (int) ans.size(); ++i) cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
}