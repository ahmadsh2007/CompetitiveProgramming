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
    int n, m, k; cin >> n >> m >> k;
    str s; cin >> s;
    str t; cin >> t;

    vector<int> pre(m + 1, n + 1);
    vector<int> suf(m + 2, -1);

    pre[0] = -1;
    int sPtr = 0;
    for (int i = 1; i <= m; ++i) {
        while (sPtr < n && s[sPtr] != t[i - 1]) sPtr++;

        if (sPtr < n) {
            pre[i] = sPtr;
            sPtr++;
        } else break;
    }

    suf[m + 1] = n;
    sPtr = n - 1;
    for (int i = m; i >= 1; --i) {
        while (sPtr >= 0 && s[sPtr] != t[i - 1]) sPtr--;
        if (sPtr >= 0) {
            suf[i] = sPtr;
            sPtr--;
        } else break;
    }

    bool possible = 0;
    for (int i = 0; i <= m; ++i) {
        int sufStart = i + k + 1;

        if (sufStart > m + 1) sufStart = m + 1;

        if (pre[i] < suf[sufStart]) {
            possible = 1;
            break;
        }
    }

    cout << (possible ? "YES" : "NO") << endl;
}

const bool TESTCASES = 1;
signed main(){
    // sieve();

    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}