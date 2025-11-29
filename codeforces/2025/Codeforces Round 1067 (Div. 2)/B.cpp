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
    // ! Wrong Solution
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    for(int i = 0; i < 2 * n; i++){
        int x; cin >> x;
        a[x]++;
    }

    i64 sum = 0;
    for(int i = 0; i < 2 * n; i++) {
        if (a[i] == 0) { continue; }
        else if (a[i] % 2 == 0) { sum += 2; }
        else sum += 1;
    }

    cout << sum << '\n';
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