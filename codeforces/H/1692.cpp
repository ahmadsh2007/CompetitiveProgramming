/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// Vector input/output operators
// I wish I could just do `v = list(map(int, input().split()))` instead of this boilerplate
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto& x:v) in>>x;
    return in;
}
// I wish I could just do `print(*v)` instead of this boilerplate
template<class T>
ostream& operator<<(ostream& out, vector<T>& v){
    for(auto& x:v) out<<x<<' ';
    return out;
}

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MOD = 1e9 + 7;
const long long INF = 1e18;

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
    int sum;
    int pre, preR;
    int suf, sufL;
    int mx, mxL, mxR;
};

Node leaf(int i, int v) {
    return {v, v, i, v, i, v, i, i};
}

void solve() {
    int n; cin >> n;
    vector<Node> x(n);
    map<int, vector<int>> map;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        map[v].push_back(i);
        x[i] = leaf(i, -1);
    }

    auto op = [](const Node& a, const Node& b) -> Node {
        Node res;
        res.sum = a.sum + b.sum;

        if (a.pre >= a.sum + b.pre) {
            res.pre = a.pre;
            res.preR = a.preR;
        }
        else {
            res.pre = a.sum + b.pre;
            res.preR = b.preR;
        }

        if (b.suf >= b.sum + a.suf) {
            res.suf = b.suf;
            res.sufL = b.sufL;
        }
        else {
            res.suf = b.sum + a.suf;
            res.sufL = a.sufL;
        }

        res.mx = a.mx;
        res.mxL = a.mxL;
        res.mxR = a.mxR;
        if (b.mx > res.mx) {
            res.mx = b.mx;
            res.mxL = b.mxL;
            res.mxR = b.mxR;
        }

        if (a.suf + b.pre > res.mx) {
            res.mx = a.suf + b.pre;
            res.mxL = a.sufL;
            res.mxR = b.preR;
        }
        return res;
    };

    Node def{0, -INF, -1, -INF, -1, -INF, -1, -1};
    SegTree<Node, decltype(op)> st(x, def);

    int ans = LLONG_MIN;
    int a, l, r;
    for (auto &[aa, p] : map) {
        for (int i : p) {
            st.update(i, leaf(i, 1));
        }

        Node root = st.query(0, n);
        if (root.mx > ans) {
            ans = root.mx;
            a = aa;
            l = root.mxL;
            r = root.mxR;
        }

        for (int i : p) {
            st.update(i, leaf(i,-1));
        }
    }

    cout << a << ' ' << l + 1 << ' ' << r + 1 << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}