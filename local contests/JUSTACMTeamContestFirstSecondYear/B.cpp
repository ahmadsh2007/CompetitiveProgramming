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
    int n, aCnt; cin >> n >> aCnt;
    int bCnt = n - aCnt;


    if (aCnt > 0) cout << 'A';
    aCnt--;

    for (int i = 0; i < bCnt - 1; ++i) cout << 'B';
    for (int i = 0; i < aCnt; ++i) cout << 'A';
    if (bCnt > 0) cout << 'B' << endl;
    else cout << endl;


}

const bool TESTCASES = 1;
signed main(){
    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}