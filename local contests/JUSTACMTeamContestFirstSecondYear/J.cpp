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
    int n, k; cin >> n >> k;

    int cnt = n / k;

    cout << cnt * (cnt + 1) / 2 << endl;
}

const bool TESTCASES = 1;
signed main(){
    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}