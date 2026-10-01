/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

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
    int l = 1, r = 1000;
    while (l <= r) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int bothCorrect = m1 * m2;
        int oneCorrect = m1 * (m2 + 1);
        int bothWrong = (m1 + 1) * (m2 + 1);
        cout << "? " << m1 << ' ' << m2 << endl;
        int val; cin >> val;
        if (val == bothCorrect) {
            l = m2 + 1;
        }
        else if (val == oneCorrect) {
            l = m1 + 1;
            r = m2 - 1;
        }
        else {
            r = m1 - 1;
        }
    }
    cout << "! " << l << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}