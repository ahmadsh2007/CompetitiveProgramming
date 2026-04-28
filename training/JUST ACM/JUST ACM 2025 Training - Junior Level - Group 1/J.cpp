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

bool check(int n, int k, int x){
    int sum = x;
    int powerCnt = 1;

    while (x / pow(k, powerCnt) > 0) {
        sum += (x / pow(k, powerCnt));
        powerCnt++;
    }

    if (sum >= n) return true;
    return false;
}

void solve() {
    int n, k; cin >> n >> k;
    
    int st = 1, end = 1e10, mid = 0, ans = 0;
    while(st <= end) {
        mid = (st + end) / 2;

        if (check(n, k, mid)){
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    cout << ans;
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}