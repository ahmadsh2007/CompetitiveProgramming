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
    int n, q; cin >> n >> q;

    map<int, vector<int>> a;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
    }

    for (auto &x : a) sort(x.second.begin(), x.second.end());

    while (q--) {
        int c, x, y; cin >> c >> x >> y;

        auto it1 = upper_bound(a[c].begin(), a[c].end(), y);
        auto it2 = lower_bound(a[c].begin(), a[c].end(), x);

        int last, first;
        if (it1 == a[c].end()) last = a[c].size();
        else last = it1 - a[c].begin();

        if (it2 == a[c].end()) first = a[c].size();
        else first = it2 - a[c].begin();

        cout << last - first << ' ';
    }

    cout << endl;
}

const bool TESTCASES = 1;
signed main(){
    // sieve();

    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}
