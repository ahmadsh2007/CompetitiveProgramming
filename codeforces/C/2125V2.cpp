#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../../Utils/debug.h"
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

vector<int> p{2, 3, 5, 7};

int rec(int x, int idx, vector<int> cur)
{
    if (idx >= (int)p.size()) {
        if (cur.empty()) return 0;
        int divide = 1;
        for (auto c : cur) divide *= c;
        // return (cur.size() & 1 ? (x / divide) : -(x / divide));
        if (cur.size() % 2) return (x / divide);
        return -(x / divide);
    }

    vector<int> curr{all(cur)};
    curr.push_back(p[idx]);
    return rec(x, idx + 1, cur) + rec(x, idx + 1, curr);
}

int helper(int x) {
    return x - rec(x, 0, {});
}

void solve() {
    int l, r; cin >> l >> r;

    cout << helper(r) - helper(l - 1) << endl;
}

const int TESTCASES = 1;
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
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}