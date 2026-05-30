#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using str = string;

bool useCur(int& cur, int& ans) {
    if (cur > 0) {
        cur--;
        ans++;
        return true;
    }
    return false;
}

bool useX(int& x, int& s, int& cur, int& ans) {
    if (x > 0) {
        x--;
        cur += s - 1;
        ans++;
        return true;
    }
    return false;
}

void solve() {
    int n, x, s; cin >> n >> x >> s;
    str t; cin >> t;

    int iCnt = count(t.begin(), t.end(), 'I');
    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; ++i) {
        if (t[i] == 'E') {
            useCur(cur, ans);
        }
        else if (t[i] == 'I') {
            iCnt--;
            useX(x, s, cur, ans);
        }
        else if (t[i] == 'A') {
            int cnt = 0;
            for (int j = i + 1; j < n && t[j] == 'E'; ++j) {
                cnt++;
            }

            bool preferX = (cnt + 1 > cur || iCnt < x);

            if (preferX) {
                if (!useX(x, s, cur, ans)) useCur(cur, ans);
            } else {
                if (!useCur(cur, ans)) useX(x, s, cur, ans);
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}