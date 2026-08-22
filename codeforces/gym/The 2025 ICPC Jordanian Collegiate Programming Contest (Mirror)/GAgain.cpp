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

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

/**
 * T: Value type stored in segment tree nodes
 * U: Lazy tag / update type
 * Op: Merge operation (T, T) -> T
 * Mapping: Apply tag to a segment value (U, T, int len) -> T
 * Composition: Merge two tags (new_tag, old_tag) -> U
 *
 * Usage Examples:
 * 1. Range Add, Range Sum:
 *    auto op = [](int a, int b) { return a + b; };
 *    auto map = [](int tag, int val, int len) { return val + tag * len; };
 *    auto comp = [](int new_tag, int old_tag) { return new_tag + old_tag; };
 *    LazySegTree<int, int, decltype(op), decltype(map), decltype(comp)> st(n, 0, op, map, comp);
 *
 * 2. Range Assignment, Range Min (No default lazy value needed!):
 *    auto op = [](int a, int b) { return min(a, b); };
 *    auto map = [](int tag, int val, int len) { return tag; };
 *    auto comp = [](int new_tag, int old_tag) { return new_tag; };
 *    LazySegTree<int, int, decltype(op), decltype(map), decltype(comp)> st(n, 2e9, op, map, comp);
 */
template<typename T, typename U, typename Op, typename Mapping, typename Composition>
class LazySegTree {
private:
    int size;
    vector<T> tree;
    vector<U> lazy;
    vector<bool> hasLazy;
    T defVal;
    Op op;
    Mapping mapping;
    Composition comp;

    void apply(int x, int len, const U& tag) {
        tree[x] = mapping(tag, tree[x], len);
        if (hasLazy[x]) lazy[x] = comp(tag, lazy[x]);
        else lazy[x] = tag, hasLazy[x] = true;
    }

    void push(int x, int lx, int rx) {
        if (!hasLazy[x]) return;

        int mid = lx + (rx - lx) / 2;
        apply(2 * x + 1, mid - lx, lazy[x]);
        apply(2 * x + 2, rx - mid, lazy[x]);
        hasLazy[x] = false;
    }

    void pull(int x) {
        tree[x] = op(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(int x, int lx, int rx, const vector<T>& a) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) tree[x] = a[lx];
            return;
        }

        int mid = lx + (rx - lx) / 2;
        build(2 * x + 1, lx, mid, a);
        build(2 * x + 2, mid, rx, a);
        pull(x);
    }

    void update(int l, int r, const U& v, int x, int lx, int rx) {
        if (lx >= r or rx <= l) return;
        if (lx >= l and rx <= r) return apply(x, rx - lx, v);
        
        push(x, lx, rx);

        int mid = lx + (rx - lx) / 2;
        update(l, r, v, 2 * x + 1, lx, mid);
        update(l, r, v, 2 * x + 2, mid, rx);
        pull(x);
    }

    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or rx <= l) return defVal;
        if (lx >= l and rx <= r) return tree[x];
        
        push(x, lx, rx);
        int mid = lx + (rx - lx) / 2;
        return op(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
    }

public:
    LazySegTree(int n, T defVal, Op op, Mapping mapping, Composition comp) 
        : defVal(defVal), op(op), mapping(mapping), comp(comp) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, defVal);
        lazy.resize(2 * size);
        hasLazy.assign(2 * size, false);
    }

    LazySegTree(const vector<T>& a, T defVal, Op op, Mapping mapping, Composition comp) 
        : LazySegTree(a.size(), defVal, op, mapping, comp) {
        build(0, 0, size, a);
    }

    // Range update: [l, r)
    void update(int l, int r, const U& v) {
        update(l, r, v, 0, 0, size);
    }

    // query function: Range query: [l, r)
    // get function:   Point query: element at position i
    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    T get(int i) {
        return query(i, i + 1);
    }
};

struct Node {
    char first = 0;
    char last = 0;
    int mask = 0;
    bool alter = true;
    bool empty = true;
};

void solve() {
    int n, q; cin >> n >> q;
    str s; cin >> s;
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) {
        a[i].empty = false;
        a[i].first = a[i].last = s[i];
        a[i].mask = (1 << (s[i] - 'a'));
        a[i].alter = true;
    }
    
    auto op = [](const Node& a, const Node& b) -> Node {
        if (a.empty) return b;
        if (b.empty) return a;

        Node res;
        res.empty = false;
        res.first = a.first;
        res.last = b.last;
        res.mask = a.mask | b.mask;
        int distinct = __builtin_popcount(res.mask);
        res.alter = a.alter && b.alter && (a.last != b.first) && (distinct <= 2);
        return res;
    };
    auto mapping = [](char c, const Node& val, int len) -> Node {
        Node res;
        res.empty = false;
        res.first = res.last = c;
        res.mask = (1 << (c - 'a'));
        res.alter = (len == 1);
        return res;
    };
    auto comp = [](char new_tag, char old_tag) -> char {
        return new_tag;
    };

    LazySegTree<Node, Node, decltype(op), decltype(mapping), decltype(comp)> lst(a, Node(), op, mapping, comp);

    while (q--) {
        str op; cin >> op;
        if (op == "SET") {
            int l, r; char c; cin >> l >> r >> c;
            Node temp;
            temp.first = temp.last = c;
            temp.alter = true;
            temp.empty = false;
            temp.mask = (1 << (c - 'a'));
            lst.update(l - 1, r, temp);
        }
        else {
            int l, r; cin >> l >> r;
            l--;
            if (r - l == 1) {
                cout << "YES\n";
            }
            else {
                Node temp = lst.query(l, r);
                int distinct = __builtin_popcount(temp.mask);
                if (temp.alter and distinct == 2) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
        }
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}