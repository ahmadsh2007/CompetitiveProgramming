#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<long long> sums;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        sums.assign(2 * size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] += v;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void set(int l, int r, int v) {
        set(l, v, 0, 0, size);
        if (r < size) set(r, -v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 0ll;
        if (lx >= l and rx <= r) return sums[x];

        int mid = lx + (rx - lx) / 2;
        long long c1 = sum(l, r, 2 * x + 1, lx, mid);
        long long c2 = sum(l, r, 2 * x + 2, mid, rx);
        return c1 + c2;
    }
    long long query(int i) {
        return sum(0, i + 1, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    SegTree st;
    st.init(n);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, v; cin >> l >> r >> v;
            st.set(l, r, v);
        }
        else {
            int i; cin >> i;
            cout << st.query(i) << endl;
        }
    }
}