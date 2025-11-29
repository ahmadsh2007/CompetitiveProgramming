#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repRef(x, a) for (auto &x : a)

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();


void solve(){
    int n, m; cin >> n >> m;

    long long ans = 0;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    rep(i, 0, m) ans -= (a[i] < 0 ? a[i] : break);
    cout << ans;

}

int main(){
// For inputs and outputs operations
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Use this template to solve, if you have test cases then don't comment, and if you don't have then comment t and while.
    // int t; std::cin >> t;
    // while(t--)
        solve();
}