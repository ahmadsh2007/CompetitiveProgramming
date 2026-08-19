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
    int sum;
};

struct SegTree {
    int size;
    vector<Node> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, {1, 1});

        for (int i = 0; i < n; i++) {
            tree[size - 1 + i] = {1, 1};
        }

        for (int i = size - 2; i >= 0; i--) {
            tree[i] = {1, (tree[2 * i + 1].sum + tree[2 * i + 2].sum) % MOD};
        }
    }

    void mul(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return;
        if (lx >= l and rx <= r) {
            tree[x].op = (tree[x].op * v) % MOD;
            tree[x].sum = (tree[x].sum * v) % MOD;
            return;
        }

        int mid = (lx + rx) / 2;
        mul(l, r, v, 2 * x + 1, lx, mid);
        mul(l, r, v, 2 * x + 2, mid, rx);

        tree[x].sum = (((tree[2 * x + 1].sum + tree[2 * x + 2].sum) % MOD) * tree[x].op) % MOD;
    }
    void mul(int l, int r, int v) {
        mul(l, r, v, 0, 0, size);
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 0;
        if (lx >= l and rx <= r) {
            return tree[x].sum;
        }

        int mid = (lx + rx) / 2;
        int m1 = get(l, r, 2 * x + 1, lx, mid);
        int m2 = get(l, r, 2 * x + 2, mid, rx);

        return ((m1 + m2) % MOD * tree[x].op) % MOD;
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
            st.mul(l, r, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.get(l, r) << endl;
        }
    }
}