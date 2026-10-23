/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

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
    
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] ^ a[i];
    }

    int ans = n * (n + 1) / 2;
    for (int i = 0; i * i <= 2 * n; i++) {
        vector<int> cnt(2 * n + 1); 
        cnt[0]++;
        for (int j = 0; j < n; j++) {
            int want = pre[j] ^ (i * i);
            if (want <= 2 * n) ans -= cnt[want];
            cnt[pre[j]]++;
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