/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct LazySegTree {
    struct Node {
        int sum = 0;
        int maxSum = 0;
        int prefix = 0;
        int suffix = 0;
        int lazy = 0;
        bool tagged = false;
    };
    int size;
    vector<Node> tree;
    LazySegTree(int n) {
        size = 1;
        while (size < n)
            size <<= 1;
        tree.assign(2 * size, {});
    }

    void apply(int x, int lx, int rx, int v) {
        int len = rx - lx;
        tree[x].sum = v * len;
        tree[x].maxSum = tree[x].prefix = tree[x].suffix = max(0ll, v * len);
        tree[x].lazy = v;
        tree[x].tagged = true;
    }

    void push(int x, int lx, int rx) {
        if (tree[x].tagged && rx - lx > 1) {
            int mid = (lx + rx) / 2;
            apply(2 * x + 1, lx, mid, tree[x].lazy);
            apply(2 * x + 2, mid, rx, tree[x].lazy);
            tree[x].tagged = false;
        }
    }

    void pull(int x) {
        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
        tree[x].maxSum = max({tree[2 * x + 1].maxSum, tree[2 * x + 2].maxSum, tree[2 * x + 1].suffix + tree[2 * x + 2].prefix});
        tree[x].prefix = max({tree[2 * x + 1].prefix, tree[2 * x + 1].sum + tree[2 * x + 2].prefix});
        tree[x].suffix = max({tree[2 * x + 2].suffix, tree[2 * x + 2].sum + tree[2 * x + 1].suffix});
    }

    void assign(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r or rx <= l)
            return;
        if (rx <= r and lx >= l) {
            apply(x, lx, rx, v);
            return;
        }

        push(x, lx, rx);

        int mid = (lx + rx) / 2;
        assign(l, r, v, 2 * x + 1, lx, mid);
        assign(l, r, v, 2 * x + 2, mid, rx);

        pull(x);
    }
    void assign(int l, int r, int v) {
        assign(l, r, v, 0, 0, size);
    }

    int query() {
        return tree[0].maxSum;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    LazySegTree lst(n);
    while (m--) {
        int l, r, v;
        cin >> l >> r >> v;
        lst.assign(l, r, v);
        cout << lst.query() << endl;
    }
}