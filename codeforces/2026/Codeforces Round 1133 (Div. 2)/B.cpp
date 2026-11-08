/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define str string

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    int k;
    cout << "? 1 " << n << endl;
    cin >> k;
    if (k == 0 or k == n) {
        return void(cout << "! NO" << endl);
    }

    cout << "? 1 " << k << endl;
    int k2; cin >> k2;
    if (k2 == k) {
        cout << "! NO" << endl;
    }
    else {
        cout << "! YES" << endl;
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}