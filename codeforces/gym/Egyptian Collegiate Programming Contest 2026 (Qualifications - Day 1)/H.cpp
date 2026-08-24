#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define str string

void solve() {
    int n; cin >> n;
    str s; cin >> s;

    int first = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] < s[i - 1]) {
            first = i;
            break;
        }
    }

    for (int i = first + 1; i < n + first; ++i) {
        if (s[i % n] < s[(i - 1) % n]) {
            return void(cout << "-1\n");
        }
    }

    cout << min(first, n - first) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}