/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;

    vector<int> lg(n + 1);
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    vector<vector<int>> sparse(lg[n] + 1, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        cin >> sparse[0][i];
    }
    for (int p = 1; p <= lg[n]; ++p) {
        for (int i = 0; i < n; ++i) {
            sparse[p][i] = gcd(sparse[p - 1][i], sparse[p - 1][(i + (1 << (p - 1))) % n]);
        }
    }

    auto query = [&](int l, int len) -> int {
        int p = lg[len];
        return gcd(sparse[p][l], sparse[p][(l + len - (1 << p)) % n]);
    };

    int l = 1, r = n;
    int mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        bool flag = true;
        for (int i = 1; i < n; ++i) {
            if (query(i, mid) != query(i - 1, mid)) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ans = mid - 1;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}