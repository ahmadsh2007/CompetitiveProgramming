/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    string s; cin >> s;

    int xorVal[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        xorVal[s[i] == '1'] ^= a[i];
    }
    
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] ^ a[i];
    }

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            xorVal[0] ^= pre[r] ^ pre[l - 1];
            xorVal[1] ^= pre[r] ^ pre[l - 1];
        }
        else {
            int g; cin >> g;
            cout << xorVal[g] << ' ';
        }
    }
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}