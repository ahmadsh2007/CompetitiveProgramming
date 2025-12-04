#include <bits/stdc++.h>
using namespace std;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    // ! Prefix Sum Arrays are always bigger than the original Array by one
    int n; cin >> n;
    vector<int> a(n);
    vector<int> pref(n + 1);

    // ? Input Example:
    // *    Index:      0  1  2  3  4  5
    // *    Array:      1  2  3  4  5  6
    // *    PreInd:  0  1  2  3  4  5  6
    // *    PrefSum: 0  1  3  6  10 15 21

    for(auto &x : a) cin >> x;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + a[i - 1];
    }

    // * I'll print Array Indices then Pref Indices
    for(int i = 0; i < n; i++) cout << '\t' << i;
    cout << '\n';
    for(int i = 0; i <= n;i++) cout << i << '\t';
    cout << "\n\n"; 


    // * Print the Array and the PrefixSum Array
    for(auto &x : a) cout << '\t' << x;
    cout << '\n';
    for(auto &x : pref) cout << x << '\t';
    cout << "\n\n";

    // TODO: I want to print the sum from L index to R index
    int l, r;
    l = n / 3, r = n / 2; // If n = 25, l = 8 and r = 12
    // cin >> l >> r;
    cout << pref[r] - pref[l - 1];
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    int T = 1;
    while (T--) solve();
    return 0;
}