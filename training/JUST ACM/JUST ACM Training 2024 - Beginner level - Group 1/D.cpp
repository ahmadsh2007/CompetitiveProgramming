#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = (a); i < (b); i++)

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();


void solve(){
    int n; cin >> n;

    int a[n];
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    rep(i, 0, n) cout << a[i] << " ";
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