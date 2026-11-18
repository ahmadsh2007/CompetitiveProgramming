/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx]++;
        }
    }

    int sum(int idx) {
        int res = 0;

        for (; idx > 0; idx -= idx & -idx) {
            res += bit[idx];
        }

        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> inv(n);
    vector<int> coord;
    for (int i = 0; i < n; ++i) {
        cin >> inv[i][0] >> inv[i][1];
        coord.push_back(inv[i][0]);
        coord.push_back(inv[i][1]);
    }

    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());

    int m = (int) coord.size();
    vector<int> p(m);
    iota(p.begin(), p.end(), 0);

    for (auto &[a, b] : inv) {
        int i = lower_bound(coord.begin(), coord.end(), a) - coord.begin();
        int j = lower_bound(coord.begin(), coord.end(), b) - coord.begin();

        swap(p[i], p[j]);
    }

    int ans = 0;
    Fenwick bit(m);
    for (int i = 0; i < m; ++i) {
        int dis = abs(coord[i] - coord[p[i]]);
        int compDis = abs(i - p[i]);

        ans += dis - compDis;
        int rank = p[i] + 1;
        int smallerOrEqual = bit.sum(rank);
        ans += i - smallerOrEqual;

        bit.add(rank);
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}