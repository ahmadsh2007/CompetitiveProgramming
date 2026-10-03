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

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    str s; cin >> s;
    int n = (int) s.size();

    int ans = 0;
    for (int d = 1; d <= n / 2; ++d) {
        int cnt = 0;
        for (int i = 0; i < n - d; ++i) {
            cnt += s[i] == s[i + d] or s[i] == '?' or s[i + d] == '?';
            if (i - d >= 0) {
                cnt -= s[i - d] == s[i] or s[i - d] == '?' or s[i] == '?';
            }
            if (i - d >= -1 and cnt == d) {
                ans = 2 * d;
            }
        }
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