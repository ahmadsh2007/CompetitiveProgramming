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
    vector<int> a(n + 1), l(n + 1), r(n + 1), ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> st;
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() and a[st.back()] >= a[i]) {
            st.pop_back();
        }
        l[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }

    st.clear();
    for (int i = n; i >= 1; --i) {
        while (!st.empty() and a[st.back()] >= a[i]) {
            st.pop_back();
        }
        r[i] = st.empty() ? n + 1 : st.back();
        st.push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        int len = r[i] - l[i] - 1;
        ans[len] = max(ans[len], a[i]);
    }
    for (int i = n - 1; i >= 1; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
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