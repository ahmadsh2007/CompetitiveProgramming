/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int v;
    int id;
};

struct SegTree {
    int size;
    vector<Node> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, {0, 0});
    }

    void add(int l, int r, int id, int v, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return;
        if (lx >= l and rx <= r) {
            tree[x].v = v;
            tree[x].id = id;
            return;
        }

        int mid = (lx + rx) / 2;
        add(l, r, id, v, 2 * x + 1, lx, mid);
        add(l, r, id, v, 2 * x + 2, mid, rx);
    }
    void add(int l, int r, int id, int v) {
        add(l, r, id, v, 0, 0, size);
    }

    void get(int i, Node & res, int x, int lx, int rx) {
        if (tree[x].id > res.id) {
            res = tree[x];
        }
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
        Node res = {0, 0};
        get(i, res, 0, 0, size);
        return res.v;
    }
};

signed main() {
    ios::sync_with_stdio(false);

    int n, q; cin >> n >> q;

    SegTree st;
    st.init(n);

    int id = 1;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, v; cin >> l >> r >> v;
            st.add(l, r, id++, v);
        }
        else {
            int i; cin >> i;
            cout << st.get(i) << endl;
        }
    }
}