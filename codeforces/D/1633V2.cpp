/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 1001;
vector<int> d(N, N);
static const int PRECOMPUTE = []() -> int {
    d[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int x = 1; x <= i; ++x) {
            int j = i + i / x;
            if (j < N) d[j] = min(d[j], d[i] + 1);
        }
    }
 
    return 0;
}();
 
void solve() {
    int n, k; cin >> n >> k;
    vector<int> b(n);
    vector<int> c(n);
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
 
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += d[b[i]];
    k = min(k, sum);
 
    vector<int> dp(k + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = k - d[b[i]]; j >= 0; --j) {
            dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
        }
    }
 
    cout << dp[k] << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT; cin >> TTT;
    while (TTT--) solve();
    return 0;
}