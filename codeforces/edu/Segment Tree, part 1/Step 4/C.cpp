#include <bits/stdc++.h>
using namespace std;

int n, m;

struct SegTree {
    int size;
    vector<vector<long long>> sums;
    vector<long long> inversions;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        sums.assign(2 * size, vector<long long>(41));
        inversions.assign(2 * size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            for (int j = 0; j <= 40; ++j) sums[x][j] = 0;
            sums[x][v] = 1;
            inversions[x] = 0;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        long long crossInv = 0;
        long long rightSmaller = 0;
        for (int c = 0; c <= 40; ++c) {
            crossInv += sums[2 * x + 1][c] * rightSmaller;
            rightSmaller += sums[2 * x + 2][c];
            sums[x][c] = sums[2 * x + 1][c] + sums[2 * x + 2][c];
        }
        inversions[x] = inversions[2 * x + 1] + inversions[2 * x + 2] + crossInv;
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair<long long, vector<long long>> getNumOfInversions(int l, int r, int x, int lx, int rx) {
        if (l >= rx or r <= lx) return {0ll, vector<long long>(41, 0)};
        if (lx >= l and rx <= r) return {inversions[x], sums[x]};

        int mid = (lx + rx) / 2;
        auto p1 = getNumOfInversions(l, r, 2 * x + 1, lx, mid);
        auto p2 = getNumOfInversions(l, r, 2 * x + 2, mid, rx);
        
        long long inv = p1.first + p2.first;
        vector<long long> sum(41, 0);
        long long rightSmaller = 0;
        
        for (int c = 0; c <= 40; ++c) {
            inv += p1.second[c] * rightSmaller;
            rightSmaller += p2.second[c];
            sum[c] = p1.second[c] + p2.second[c];
        }
        
        return {inv, sum};
    }
    
    long long getNumOfInversions(int l, int r) {
        return getNumOfInversions(l, r, 0, 0, size).first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    SegTree st;
    st.init(n + 1);

    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        st.set(i, v);
    }

    for (int i = 1; i <= m; ++i) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            cout << st.getNumOfInversions(l, r + 1) << endl;
        }
        else {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
    }
}