#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Op = std::plus<T>>
class SegTree {
    /*
    Recursive init
    SegTree<long long> sum_tree(a, 0LL); // Defaults to std::plus
    SegTree<long long, std::max<long long>> max_tree(a, -1e18);
    */
private:
    int size;
    vector<T> tree;
    T def;
    Op op;

    void build(int x, int lx, int rx, const vector<T>& a) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) tree[x] = a[lx];
            return;
        }
        int mid = lx + (rx - lx) / 2;
        build(2 * x + 1, lx, mid, a);
        build(2 * x + 2, mid, rx, a);
        tree[x] = op(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, T v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = lx + (rx - lx) / 2;
        if (i < mid) update(i, v, 2 * x + 1, lx, mid);
        else         update(i, v, 2 * x + 2, mid, rx);
        tree[x] = op(tree[2 * x + 1], tree[2 * x + 2]);
    }

    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or  rx <= l) return def;     // Disjoint
        if (lx >= l and rx <= r) return tree[x]; // Fully inside
        int mid = lx + (rx - lx) / 2;
        return op(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
    }

public:
    SegTree(int n, T def = T()) : def(def) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, def);
    }
    
    SegTree(const vector<T>& a, T def = T()) : SegTree(a.size(), def) {
        build(0, 0, size, a);
    }

    void update(int i, T v) {
        update(i, v, 0, 0, size);
    }
    void add(int i, T v) {
        update(i, op(get(i), v));
    }

    // [l, r)
    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    T get(int i) {
        return query(i, i + 1);
    }
};

// Iterative Segment Tree
template <typename T, class F = function<T(const T&, const T&)>>
class SegTree {
    /*
    Iterative init (passing lambda)
    Using example:
    SegTree<long long> iter_sum(a, 0LL, [](long long x, long long y) { return x + y; });
    */

    int n;
    vector<T> tree;
    T def;
    F combine;

public:
    SegTree(int n, T def, F combine) : n(n), tree(2 * n, def), def(def), combine(combine) {}
    
    SegTree(const vector<T>& v, T def, F combine) : SegTree(v.size(), def, combine) {
        for (int i = 0; i < n; i++) tree[n + i] = v[i];
        for (int i = n - 1; i > 0; i--) tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int p, T val) {
        for (tree[p += n] = val; p >>= 1; ) tree[p] = combine(tree[p << 1], tree[p << 1 | 1]);
    }

    void add(int p, T val) {
        update(p, combine(tree[p + n], val));
    }

    T query(int l, int r) { // [l, r)
        T resl = def, resr = def;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = combine(resl, tree[l++]);
            if (r & 1) resr = combine(tree[--r], resr);
        }
        return combine(resl, resr);
    }

    T get(int p) { return tree[p + n]; }
};