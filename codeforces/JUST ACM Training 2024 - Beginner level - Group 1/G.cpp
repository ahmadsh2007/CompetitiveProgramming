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
    int n; cin >> n;

    int index1, indexN;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) index1 = i;
        if (a[i] == n) indexN = i;
    }
    cout << max(max(n - index1 - 1, n - indexN - 1), max(indexN - 0, index1 - 0)) << '\n';


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