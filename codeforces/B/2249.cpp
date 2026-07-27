#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 998244353;

void solve() {
    int n; cin >> n;

    bool end = 0;
    vector<int> a(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
        if (a[i] == n) end = 1;
    }
    if (end) return void(cout << "0\n");

    vector<bool> pre(n, 1);
    for (int i = 1; i < n - 1; ++i) {
        pre[i] = pre[i - 1] and (a[i] >= a[i - 1]);
    }

    vector<bool> suf(n, 1);
    for (int i = n - 3; i >= 0; --i) {
        suf[i] = suf[i + 1] and (a[i] >= a[i + 1]);
    }

    int tot = 0;

    for (int cut = 0; cut < n; ++cut) {
        bool isPreValid = (cut == 0) ? true : pre[cut - 1];
        bool isSufValid = (cut == n - 1) ? true : suf[cut];
        if (!isPreValid or !isSufValid) continue;
        if (cut > 0 && cut < n - 1 && a[cut - 1] == a[cut]) continue;

        int l = 0, r = n - 2;
        int used = 0;
        int ways = 1;
        vector<int> vis(n + 1, 0);

        while (l < cut or r >= cut) {
            int val;
            if (l >= cut) val = a[r--];
            else if (r < cut) val = a[l++];
            else if (a[l] < a[r]) val = a[l++];
            else if (a[l] > a[r]) val = a[r--];
            else { ways = 0; break; }

            if (!vis[val]) vis[val] = 1;
            else if (val < used) {
                ways = 0;
                break;
            }
            else ways = (ways * (val - used)) % MOD;
            used++;
        }

        tot = (tot + ways) % MOD;
    }

    cout << tot << endl;;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}