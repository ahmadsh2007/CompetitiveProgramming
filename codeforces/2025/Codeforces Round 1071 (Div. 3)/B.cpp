#include <bits/stdc++.h>
using namespace std;

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
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int sum = 0;
    for (int i = 0; i + 1 < n; i++) sum += llabs(a[i] - a[i + 1]);

    int rm = max({rm, llabs(a[0] - a[1]), llabs(a[n - 2] - a[n - 1])});

    for (int i = 1; i < n - 1; i++) {
        rm = max(rm, llabs(a[i - 1] - a[i]) + llabs(a[i] - a[i + 1]) - llabs(a[i - 1] - a[i + 1]));
    }

    cout << (sum - rm) << "\n";
}

#undef int
int main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}