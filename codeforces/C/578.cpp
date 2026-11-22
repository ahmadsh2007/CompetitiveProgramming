/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    double res[2];
    auto check = [&](double m1, double m2) -> bool {
        res[0] = res[1] = 0;
        double mn[2] = {0, 0};
        double mx[2] = {0, 0};
        double cur[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            cur[0] += a[i] - m1;
            cur[1] += a[i] - m2;

            for (int j = 0; j < 2; ++j) {
                mn[j] = min(mn[j], cur[j]);
                mx[j] = max(mx[j], cur[j]);
            }
        }

        res[0] = mx[0] - mn[0];
        res[1] = mx[1] - mn[1];
        return res[0] <= res[1];
    };

    double l = -10000, r = 10000;
    double m1, m2, ans = 1e18;
    for (int i = 0; i < 100; ++i) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        if (check(m1, m2)) {
            r = m2;
        }
        else {
            l = m1;
        }

        ans = min({ans, res[0], res[1]});
    }

    cout << fixed << setprecision(15) << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}