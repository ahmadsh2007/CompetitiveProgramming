#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<long long> ones;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        ones.assign(2 * size, 0ll);
    }

    void set(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            ones[x] ^= 1;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, 2 * x + 1, lx, mid);
        }
        else {
            set(i, 2 * x + 2, mid, rx);
        }
        ones[x] = ones[2 * x + 1] + ones[2 * x + 2];
        return;
    }
    void set(int i) {
        set(i, 0, 0, size);
    }

    int kth(int k, int x, int lx, int rx) {
        if (rx - lx == 1) return lx;

        int mid = lx + (rx - lx) / 2;
        if (ones[2 * x + 1] > k) {
            return kth(k, 2 * x + 1, lx, mid);
        }
        else {
            return kth(k - ones[2 * x + 1], 2 * x + 2, mid, rx);
        }
    }
    int kth(int k) {
        return kth(k, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    SegTree st;
    st.init(n);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x) st.set(i);
    }
    
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int i; cin >> i;
            st.set(i);
        }
        else {
            int k; cin >> k;
            cout << st.kth(k) << endl;
        }
    }
}