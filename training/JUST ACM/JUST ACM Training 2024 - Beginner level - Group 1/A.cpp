#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();


void solve(){
    int x, y, z; cin >> x >> y >> z;
    bool ok = 0;
    if (x + y >= 10 || x + z >= 10 || y + z >= 10) ok = 1;

    cout << (ok ? "YES\n" : "NO\n");
}

int main(){
// For inputs and outputs operations
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Use this template to solve, if you have test cases then don't comment, and if you don't have then comment t and while.
    int t; std::cin >> t;
    while(t--)
        solve();
}