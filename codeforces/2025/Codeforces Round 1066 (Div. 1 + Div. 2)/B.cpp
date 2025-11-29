#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    long long n, x, y; cin >> n >> x >> y;
    string s; cin >> s;

    long long counts4 = 0, counts8 = 0;
    for (char c : s) {
        if (c == '4') counts4 += 1;
        else counts8 += 1;
    }

    long long ax = llabs(x);
    long long ay = llabs(y);

    long long dx = 0, dy = 0;
    if (ax > counts8) dx = ax - counts8;
    if (ay > counts8) dy = ay - counts8;

    long long dist = dx + dy;

    if (dist <= counts4) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}