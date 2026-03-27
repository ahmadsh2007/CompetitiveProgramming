/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> prefix(n + 1);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];

    auto check = [&](int l, int mid) -> bool {
        int piles = mid - l + 1;
        cout << "? " << piles;
        for (int i = l; i <= mid; ++i) cout << " " << i;
        cout << endl;

        int judge; cin >> judge;
        return judge == prefix[mid] - prefix[l - 1];
    };

    int l = 1, r = n, mid, ans = n;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(l, mid)) l = mid + 1;
        else {
            ans = mid;
            r = mid - 1;
        }
    }

    cout << "! " << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    while (TTT--) solve();
    return 0;
}