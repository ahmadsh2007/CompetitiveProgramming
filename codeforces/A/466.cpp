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
    int n, m, a, b; cin >> n >> m >> a >> b;

    int total = 0;
    if (m * a <= b){
        total = n * a;
    } else {
        int multi = n / m;
        n %= m;
        total = multi * b + min(n * a, b);
    }

    cout << total << '\n';
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}