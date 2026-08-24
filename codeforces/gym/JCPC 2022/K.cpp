#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = (int) s.size();
    if (n == 1 and s[0] == '1') {
        return void(cout << "NO\n");
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hobz.in", "r", stdin);

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}