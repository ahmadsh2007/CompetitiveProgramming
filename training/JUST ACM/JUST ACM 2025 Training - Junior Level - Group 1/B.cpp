#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../Utils/debug.h"
#endif

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
    int n; cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> validIndices;
    for (int i = 1; i <= n; i++)
        if (a[i] < i) validIndices.push_back(i);

    int ans = 0;
    for (auto j : validIndices) {
        auto it = lower_bound(validIndices.begin(), validIndices.end(), a[j]);
        int count = it - validIndices.begin();
        
        ans += count;
    }

    cout << ans << endl;
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}