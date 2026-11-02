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
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
    }

    cout << "? 1 1 1" << endl;
    int v; cin >> v;
    vector<int> ans(n + 1);
    if (v == 1 or v == -1) {
        ans[1] = v;
        for (int i = 2; i <= n; ++i) {
            cout << "? 1 1 " << i << endl;
            int w; cin >> w;
            ans[i] = w - v;
        }
        cout << "!";
        for (int i = 1; i <= n; ++i) {
            cout << ' ' << ans[i];
        }
        cout << endl;
        return;
    }
    
    if (v == 0) {
        ans[1] = 0;
    }
    else if (v < 0) {
        cout << "? 2 1" << endl;
        ans[1] = 1;
    }
    else {
        cout << "? 2 1" << endl;
        ans[1] = -1;
    }

    for (int i = 2; i <= n; ++i) {
        cout << "? 1 1 " << i << endl;
        int w; cin >> w;
        ans[i] = w;
    }
    if (ans[1] == 0) {
        cout << "? 2 1" << endl;
        cout << "? 1 1 1" << endl;
        int w; cin >> w;
        ans[1] = (w > 0 ? 1 : -1);
    }

    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << ' ' << ans[i];
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