/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct SegTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return;
        if (lx >= l and rx <= r) {
            tree[x] = max(tree[x], v);
            return;
        }

        int mid = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, mid);
        add(l, r, v, 2 * x + 2, mid, rx);
    }
    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    void get(int i, int & res, int x, int lx, int rx) {
        res = max(res, tree[x]);
        if (rx - lx == 1) {
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            get(i, res, 2 * x + 1, lx, mid);
        }
        else {
            get(i, res, 2 * x + 2, mid, rx);
        }
    }
    int get(int i) {
        int res = 0;
        get(i, res, 0, 0, size);
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;

    SegTree st;
    st.init(n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, v; cin >> l >> r >> v;
            st.add(l, r, v);
        }
        else {
            int i; cin >> i;
            cout << st.get(i) << endl;
        }
    }
}