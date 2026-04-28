/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int k = n - 1;

    vector<int> a(n);
    vector<char> op(n - 1);
    cin >> a[0];
    for (int i = 1; i < n; ++i) cin >> op[i - 1] >> a[i];

    string temp = "";
    for (int i = 0; i < n - 1; ++i) if (op[i] == '+') op[i] = '1'; else op[i] = '0';
    for (int i = 0; i < n - 1; ++i) temp += op[i];
    int number = stoll(temp, nullptr, 2);

    // * + - -
    // * 1 0 0
    // 2 3 5 7

    int mx = (1ll << k);
    int ans = 1e18;
    for (int i = 0; i < mx; ++i) {
        int cur = a[0];
        for (int j = k - 1; j >= 0; --j) {
            if ((i >> j) & 1) {
                cur += a[n - 1 - j];
            } else cur -= a[n - 1 - j];
        }

        if (cur == 0) {
            int diff = 0;
            for (int j = k - 1; j >= 0; --j) {
                int bit1 = (i >> j) & 1;
                int bit2 = (number >> j) & 1;

                diff += (bit1 != bit2);
            }
            ans = min(ans, diff);
        }
    }

    cout << (ans == 1e18 ? -1 : ans) << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}