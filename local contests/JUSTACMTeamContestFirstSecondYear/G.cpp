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
    int x, y; cin >> x >> y;

    if (gcd(x, y) != 1) cout << 0 << endl;
    else if (gcd(x + 1, y) != 1 || gcd(x, y + 1) != 1) cout << 1 << endl;
    else cout << 2 << endl;
}

const bool TESTCASES = 1;
signed main(){
    // sieve();

    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}