/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) (int)(x).size()
// #define endl '\n'
// #define int long long
// #define str string // What a Python

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const vector<int> SPECIAL = {4, 8, 15, 16, 23, 42};

int findCommon(int p1, int p2) {
    for (int x : SPECIAL) if (p1 % x == 0 && p2 % x == 0)
    for (int y : SPECIAL) if (p1 / x == y)
    for (int z : SPECIAL) if (p2 / x == z)
    if (x != y && x != z && y != z) return x;
}

void solve() {
    vector<int> ret(4), ans(6);
    cout << "? 1 2" << endl;
    cin >> ret[0];
    cout << "? 2 3" << endl;
    cin >> ret[1];
    cout << "? 4 5" << endl;
    cin >> ret[2];
    cout << "? 5 6" << endl;
    cin >> ret[3];

    ans[1] = findCommon(ret[0], ret[1]);
    ans[0] = ret[0] / ans[1];
    ans[2] = ret[1] / ans[1];

    ans[4] = findCommon(ret[2], ret[3]);
    ans[3] = ret[2] / ans[4];
    ans[5] = ret[3] / ans[4];

    cout << "!";
    for (auto x : ans) cout << ' ' << x;
    cout << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    while (TTT--) solve();
    return 0;
}