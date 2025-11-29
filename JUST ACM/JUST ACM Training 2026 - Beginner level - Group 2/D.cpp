#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define str string // What a Python

using i64 = long long;
using u64 = unsigned long long;
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

    vector<int> a(n);
    for(auto &x : a) cin >> x;

    if(a[0] == -1 && a[n - 1] == -1) for (auto &x : a) x == -1 ? x = 0 : x = x;
    for (int i = 1; i < n - 1; i++) a[i] == -1 ? a[i] = 0 : a[i] = a[i];

    int sum = 0;
    for (int i = 1; i < n; i++) sum += a[i] - a[i - 1];

    if (a[0] == -1) {
        if (sum > 0) {
            a[0] = sum - 1;
            sum = 0;
        } else a[0] = 0;

        cout << -sum << '\n';
        for (auto x : a) cout << x << ' ';
        cout << '\n';
        return;
    } else if (a[n - 1] == -1) {
        if (sum < 0){
            a[n - 1] = -sum - 1;
            sum = 0;
        } else a[n - 1] = 0;

        cout << sum << '\n';
        for (auto x : a) cout << x << ' ';
        cout << '\n';
        return;
    }

    cout << abs(sum) << '\n';
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}