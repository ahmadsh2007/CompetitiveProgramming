/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

template<typename T, typename Op = std::plus<T>>
class SegTree {
    /*
    Recursive init
    SegTree<long long> sum_tree(a, 0LL); // Defaults to std::plus
    SegTree<long long, std::max<long long>> max_tree(a, -1e18);
    SegTree<int, decltype([](const int & x, const int & y) -> int { return gcd(x, y); })> maximumModuloEquality(d, 0ll);
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

struct Node {
    int sum = 0, pref = 0, suf = 0, best = 0;
    bool full = true;
};

struct Merge {
    Node operator()(const Node& L, const Node& R) const {
        Node res;
        res.full = L.full and R.full;
        res.sum  = L.sum + R.sum;
        res.pref = L.full ? L.sum + R.pref : L.pref;
        res.suf  = R.full ? R.sum + L.suf  : R.suf;
        res.best = max({L.best, R.best, L.suf + R.pref});
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<Node> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        a[i] = {x, x, x, x, true};
    }

    SegTree<Node, Merge> st(a, Node());
    Node destroyed{0, 0, 0, 0, false};

    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        st.update(k, destroyed);
        cout << st.query(0, n + 1).best << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}