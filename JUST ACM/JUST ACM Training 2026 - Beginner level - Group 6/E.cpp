#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using ull = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    string s; cin >> s;

    vector<int> a(s.size() + 1);
    for (int i = 1; i < s.size(); i++) a[i] = (s[i] == s[i - 1]);

    vector<int> pre(s.size() + 1);
    for (int i = 1; i <= s.size(); i++) pre[i] = pre[i - 1] + a[i];

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << endl;
    }
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}