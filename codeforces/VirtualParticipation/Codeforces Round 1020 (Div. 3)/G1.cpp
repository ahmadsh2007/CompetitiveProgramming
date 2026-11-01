/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
    }

    int root = -1;
    vector<int> ans(n + 1);
    vector<int> cur(n + 1);
    int temp = -10;
    int f1 = -10;
    bool isRoot = true;
    auto check = [&]() -> bool {
        cout << "? 1 1 1" << endl;
        int v; cin >> v;

        if (v == 1 or v == -1) {
            ans[1] = v;
            return false;
        }

        if (temp == -10) temp = v;
        else {
            ans[1] = (v - temp) / 2;
        }
        f1 = v;
        return true;
    };
    if (check()) {
        isRoot = false;
        cout << "? 2 1" << endl;
        check();
    }

    if (isRoot) {
        for (int i = 2; i <= n; ++i) {
            cout << "? 1 1 " << i << endl;
            int v; cin >> v;
            ans[i] = v - ans[1];
        }
        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    else {
        auto askRange = [&](int l, int r) -> int {
            cout << "? 1 " << (r - l + 1);
            for (int i = l; i <= r; ++i) cout << ' ' << i;
            cout << endl;

            int s; cin >> s;
            return s;
        };

        int l = 2, r = n;
        int mid, k;
        while (l <= r) {
            mid = l + (r - l) / 2;
            k = mid - l + 1;
            int s1 = askRange(l, mid);
            cout << "? 2 1" << endl;
            ans[1] = -ans[1];
            f1 += 2 * ans[1];
            int s2 = askRange(l, mid);
            if (abs(s2 - s1) / 2 == k) {
                l = mid + 1;
            }
            else {
                root = mid;
                r = mid - 1;
            }
        }

        for (int i = 2; i <= n; ++i) {
            cout << "? 1 1 " << i << endl;
            int v; cin >> v;
            ans[i] = (i == root ? v : v - f1);
        }
        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}