/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, m, x; cin >> n >> m >> x;
    set<int> q[2];
    int used = 0;
    q[used].insert(x);
    for (int i = 0; i < m; ++i) {
        int d; char c; cin >> d >> c;
        while (!q[used].empty()) {
            int u = *(q[used].begin());
            q[used].erase(u);
            if (c == '?' or c == '0') q[used ^ 1].insert((u + d - 1) % n + 1);
            if (c == '?' or c == '1') q[used ^ 1].insert((u - d - 1 + n) % n + 1);
        }
        used ^= 1;
    }
    cout << (int) q[used].size() << endl;
    for (auto &x : q[used]) cout << x << ' ';
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}