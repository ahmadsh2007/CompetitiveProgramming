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

void queries(int totSum, const vector<int> &pre){
    int l, r, k; cin >> l >> r >> k;

    int curSum = pre[r] - pre[l - 1];
    int len = r - l + 1;
    int newSum = totSum - curSum + k * len;

    if (newSum % 2 == 1) cout << "YES\n";
    else cout << "NO\n";

}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    vector<int> pre(n + 1);
    for(auto &x : a) cin >> x;
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i - 1];

    while(q--) queries(pre[n], pre);
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}