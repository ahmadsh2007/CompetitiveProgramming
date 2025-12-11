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
    // So simply and in general we take the biggest odd and the prefix of evens unless there is an edge case, fuck it
    int n; cin >> n;
    vector<int> odds, evens;
    
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x % 2) odds.push_back(x);
        else evens.push_back(x);
    }

    sort(rall(odds));
    sort(rall(evens));

    int oddSize = odds.size();
    int evenSize = evens.size();

    vector<int> preEven(evenSize + 1);
    for (int i = 0; i < evenSize; i++) 
        preEven [i + 1] = preEven[i] + evens[i];

    for (int k = 1; k <= n; k++) {
        int mn;
        if (1 > k - evenSize) mn = 1;
        else mn = k - evenSize;
        
        if (!(mn % 2)) mn++;

        if (mn > oddSize || mn > k || !oddSize) cout << 0 << " ";
        else cout << odds[0] + preEven[k - mn] << " ";
    }
    
    cout << "\n";
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}