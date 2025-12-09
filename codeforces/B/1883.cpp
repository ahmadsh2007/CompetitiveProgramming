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

void solve(int t) {
    int n, k; cin >> n >> k;
    vector<int> freq(26);
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        int x = ch - 'a';
        freq[x]++;
    }

    int oddCounts = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2) oddCounts++;
    }

    if (oddCounts > k) cout << "NO\n";
    else cout << "YES\n";
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
    while (T--) solve(T);
    return 0;
}