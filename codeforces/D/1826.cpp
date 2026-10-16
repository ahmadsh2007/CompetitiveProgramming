/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    /*
        b_i1 + b_i2 + b_i3 - (r - l)
        Let's say we always take the first and the last element in the range,
        because if we don't then we can't cut the range and make it shorts (higher score)

        b_l + b_i2 + b_r - (r - l): (b_l + l) + b_i2 + (b_r - r)
    */

    int b_l[n], b_r[n];
    for (int i = 0; i < n; ++i) {
        b_l[i] = a[i] + i;
        b_r[i] = a[i] - i;
    }

    for (int i = 0; i < n; ++i) {
        cerr << b_l[i] << ' ' << b_r[i] << endl;
    }
    cerr << endl;

    int dp[n] = {0};
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i - 1], b_l[i - 2]);
    }

    int prefix[n], suffix[n];
    prefix[0] = b_l[0];
    suffix[n - 1] = b_r[n - 1];
    for (int i = 1; i < n; ++i) {
        prefix[i] = max(prefix[i - 1], b_l[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        suffix[i] = max(suffix[i + 1], b_r[i]);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, a[i] + prefix[i - 1] + suffix[i + 1]);
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}