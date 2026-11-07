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

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(q);
    for (auto &x : a) cin >> x;
    
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = i + 1;
    }
    
    for (int i = 0; i < q; ++i) {
        reverse(ans.begin(), ans.begin() + a[i]);
        for (int j = 0; j < a[i]; ++j) {
            ans[j] = -ans[j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}