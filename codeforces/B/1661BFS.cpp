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

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;

        int ans = 15;
        for (int add = 0; add <= 15; ++add) {
            for (int mul = 0; mul <= 15; ++mul) {
                if (((x + add) << mul) % 32768 == 0) {
                    ans = min(ans, add + mul);
                }
            }
        }
        cout << ans << " \n"[i == n - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}