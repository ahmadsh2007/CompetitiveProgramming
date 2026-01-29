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

#define vi   vector<int>
#define vill vector<ll>
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

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
    str s; cin >> s;

    // Whoever wrote the questions, I hate you
    vi ones;
    for (int i = 0; i < n; i++) if (s[i] == '1') ones.push_back(i);

    if (ones.empty()) {
        cout << (n + 2) / 3 << "\n";
        return;
    }

    int total = ones.size();

    int x = ones[0];
    total += (x + 1) / 3;

    int zeroesAfter = n - 1 - ones.back();
    total += (zeroesAfter + 1) / 3;

    for (int i = 0; i < (int)ones.size() - 1; i++) {
        int gap = ones[i + 1] - ones[i] - 1;
        total += gap / 3;
    }

    cout << total << "\n";
}

bool TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}