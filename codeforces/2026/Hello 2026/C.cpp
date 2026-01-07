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

#define _vi1(a) vector<int> a;
#define _vi2(a,n) vector<int> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vi(...) GET_MACRO(__VA_ARGS__, _vi2, _vi1)(__VA_ARGS__)
#define _vill1(a) vector<long long> a;
#define _vill2(a,n) vector<long long> a(n);
#define GET_MACRO(_1,_2,NAME,...) NAME
#define vill(...) GET_MACRO(__VA_ARGS__, _vill2, _vill1)(__VA_ARGS__)
#define read(v) for (auto &x : v) cin >> x;

using i64 = long long;
using ll  = long long;
using u64 = unsigned long long;
using uint = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

bool check(int extra, int n, int m, int k) {
    if (extra == 0) return true;

    int leftSpaces = k - 1;
    int rightSpaces = n - k;
    int l = extra / 2;
    int r = extra - l;

    if (l > leftSpaces) {
        r += (l - leftSpaces);
        l -= (l - leftSpaces);
    }
    else if (r > rightSpaces) {
        l += (r - rightSpaces);
        r -= (r - rightSpaces);
    }
    if (l > leftSpaces || r > rightSpaces) return false;
    int a = max(l, r);
    int b = min(l, r);
    int ans = 2 * a + b - 1;

    return ans <= m;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int l = 0, r = n - 1;
    int ans = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid, n, m, k)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans + 1 << endl;
}

#undef int
int main() {
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

    uint T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}