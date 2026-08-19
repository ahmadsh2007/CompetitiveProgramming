/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

struct Node {
    int op;
    int an;
};

struct SegTree {
    int size;
    vector<Node> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, {0, 0});
    }

    void orOP(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return;
        if (lx >= l and rx <= r) {
            tree[x].op |= v;
            tree[x].an |= v;
            return;
        }

        int mid = (lx + rx) / 2;
        orOP(l, r, v, 2 * x + 1, lx, mid);
        orOP(l, r, v, 2 * x + 2, mid, rx);

        tree[x].an = (tree[2 * x + 1].an & tree[2 * x + 2].an) | tree[x].op;
    }
    void orOP(int l, int r, int v) {
        orOP(l, r, v, 0, 0, size);
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return LLONG_MAX;
        if (lx >= l and rx <= r) {
            return tree[x].an;
        }

        int mid = (lx + rx) / 2;
        int m1 = get(l, r, 2 * x + 1, lx, mid);
        int m2 = get(l, r, 2 * x + 2, mid, rx);

        return ((m1 & m2) | tree[x].op);
    }
    int get(int l, int r) {
        return get(l, r, 0, 0, size);
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
            st.orOP(l, r, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.get(l, r) << endl;
        }
    }
}