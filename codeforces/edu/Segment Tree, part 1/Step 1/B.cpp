#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<long long> mins;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        mins.assign(2 * size, 1e9 + 5);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x] = v;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        return;
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long getMin(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 1e9 + 5;
        if (lx >= l and rx <= r) return mins[x];

        int mid = lx + (rx - lx) / 2;
        long long m1 = getMin(l, r, 2 * x + 1, lx, mid);
        long long m2 = getMin(l, r, 2 * x + 2, mid, rx);
        return min(m1, m2);
    }
    long long getMin(int l, int r) {
        return getMin(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    SegTree st;
    st.init(n);

    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        st.set(i, v);
    }
    
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.getMin(l, r) << endl;
        }
    }
}