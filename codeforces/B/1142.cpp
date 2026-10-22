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

const int LOG = 18;
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

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> p(n + 1);
    vector<int> a(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    vector<int> prev(n + 1);
    prev[p[1]] = p[n];
    for (int i = 2; i <= n; ++i) {
        prev[p[i]] = p[i - 1];
    }

    vector<vector<int>> lca(LOG, vector<int>(m + 1));
    vector<int> lastSeen(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
        lca[0][i] = lastSeen[prev[a[i]]];
        lastSeen[a[i]] = i;
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= m; ++i) {
            lca[j][i] = lca[j - 1][lca[j - 1][i]];
        }
    }

    vector<int> start(m + 1);
    for (int i = 1; i <= m; ++i) {
        int cur = i, steps = n - 1;
        for (int j = 0; j < LOG and cur; ++j) {
            if ((steps >> j) & 1) cur = lca[j][cur];
        }
        start[i] = cur;
    }

    auto op = [](const int &a, const int &b) -> int {
        return max(a, b);
    };

    SegTree<int, decltype(op)> st(start, 0);

    string ans(q, '0');
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        if (st.query(l, r + 1) >= l) ans[i] = '1';
    }
    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}