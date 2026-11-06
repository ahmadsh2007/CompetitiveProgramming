/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 998244353;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 5001;
int bell[N];
int C[N][N];
int dp[N];

auto add = [](const int & a, const int & b) -> int {
    return (a + b) % MOD;
};
auto mul = [](const int & a, const int & b) -> int {
    return (a * b) % MOD;
};

auto PRECOMPUTE = [](){
    for (int i = 0; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
        }
    }
    bell[0] = 1;
    for (int i = 1; i < N; ++i) {
        for (int k = 0; k < i; ++k) {
            bell[i] = add(bell[i], mul(C[i - 1][k], bell[i - k - 1]));
        }
    }
    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        if (i >= 2) {
            dp[i] = add(dp[i], dp[i - 2]);
        }
        if (i >= 3) {
            dp[i] = add(dp[i], dp[i - 3]);
        }
    }
    return 0;
}();

void solve() {
    int n; cin >> n;
    str s; cin >> s;

    int cnt[2] = {0, 0};
    int cur = 0;
    int ans = 1, val = 0;
    for (int i = 0; i < n; ++i) {
        bool flag = false;
        if (i > 0 and s[i] != s[i - 1]) flag = true;
        if (i < n - 1 and s[i] != s[i + 1]) flag = true;
        if (i > 0 and s[i] == s[i - 1]) {
            ans = mul(ans, dp[cur]);
            cur = 0;
        }
        if (flag) {
            cur++;
            val += 2;
        }
        else {
            ans = mul(ans, dp[cur]);
            cur = 0;
            cnt[s[i] == '1']++;
            val++;
        }
    }

    ans = mul(ans, dp[cur]);
    ans = mul(ans, bell[cnt[0]]);
    ans = mul(ans, bell[cnt[1]]);

    cout << val << ' ' << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}