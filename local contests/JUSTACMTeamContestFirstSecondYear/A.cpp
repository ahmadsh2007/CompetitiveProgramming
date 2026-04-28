#include <bits/stdc++.h>

using namespace std;

#define int long long
#define str string // Welcome back Python
                   // And no Ayham I didn't copy it, I just wrote the comment like CHAD.
#define endl '\n'

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int SPEED_UP = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


void solve() {
    int n, k, t; cin >> n >> k >> t;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    set<int> curWindow;

    for (int i = 0; i < n; ++i) {
        while ((int) curWindow.size() > 0 && a[i] - *curWindow.begin() >= t) {
            auto it = curWindow.begin();
            curWindow.erase(it);
        }

        if ((int) curWindow.size() >= k) {
            cout << "R";
        } else {
            curWindow.insert(a[i]);
            cout << "A";
        }
    }

    cout << endl;
}

const bool TESTCASES = 1;
signed main(){
    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}