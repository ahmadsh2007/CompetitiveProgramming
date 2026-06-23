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
const int K = 1e6 + 2;
int d[N];
static const int PRECOMPUTE = []() -> int {
    for (int i = 2; i < N; ++i) d[i] = N;
    d[1] = 0;
    for (int i = 1; i < N; ++i) {
        for (int x = 1; x <= i; ++x) {
            int j = i + i / x;
            if (j < N) d[j] = min(d[j], d[i] + 1);
        }
    }

    return 0;
}();

int b[N], c[N];
int dp[K];
int n, k;
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    for (int i = 0; i <= k; ++i) dp[i] = 0;
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