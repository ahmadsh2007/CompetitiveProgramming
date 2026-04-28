#include <bits/stdc++.h>

using namespace std;

#define int long long
#define str string // Welcome back Python
                   // And no Ayham I didn't copy it, I just wrote the comment like CHAD.
#define endl '\n'

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int SPEED_UP = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> nextGreater(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.top()] < a[i]) {
            nextGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        if (nextGreater[i] == -1) ans[i] = 1;
        else ans[i] = 1 + ans[nextGreater[i]];
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}

const bool TESTCASES = 1;
signed main(){
    // sieve();

    int t = 1;
    if (TESTCASES) cin >> t;
    while (t--) solve();
    return 0;
}