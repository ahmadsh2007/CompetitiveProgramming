#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<int> mx;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        mx.assign(2 * size, -1);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mx[x] = v;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        mx[x] = max(mx[2 * x + 1], mx[2 * x + 2]);
        return;
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int findJ(int v, int x, int lx, int rx) {
        if (rx - lx == 1) return lx;

        int mid = lx + (rx - lx) / 2;
        if (mx[2 * x + 1] >= v) {
            return findJ(v, 2 * x + 1, lx, mid);
        }
        else return findJ(v, 2 * x + 2, mid, rx);
    }
    int findJ(int v) {
        if (mx[0] < v) return -1;
        return findJ(v, 0, 0, size);
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
            int x; cin >> x;
            cout << st.findJ(x) << endl;
        }
    }
}