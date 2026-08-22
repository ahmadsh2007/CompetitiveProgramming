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

struct Node {
    int sum;
    int max;
};

struct LazySegTree {
    int size;
    vector<Node> tree;

    void pull(int x) {
        tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
        tree[x].max = max(tree[2 * x + 1].max, tree[2 * x + 2].max);
    }

    void build(int x, int lx, int rx, const vector<int> &a) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) {
                tree[x].sum = a[lx];
                tree[x].max = a[lx];
            }
            return;
        }
        int mid = lx + (rx - lx) / 2;
        build(2 * x + 1, lx, mid, a);
        build(2 * x + 2, mid, rx, a);
        pull(x);
    }

    LazySegTree(const vector<int> &a) {
        size = 1;
        while (size < (int) a.size()) size *= 2;
        tree.assign(2 * size, Node{0, 0});
        build(0, 0, size, a);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x].sum = tree[x].max = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        pull(x);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r or l >= rx or tree[x].max < v) return;

        if (rx - lx == 1) {
            tree[x].sum = tree[x].max %= v;
            return;
        }

        int mid = (lx + rx) / 2;
        update(l, r, v, 2 * x + 1, lx, mid);
        update(l, r, v, 2 * x + 2, mid, rx);
        pull(x);
    }
    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 0ll;
        if (lx >= l and r >= rx) return tree[x].sum;

        int mid = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid, rx);
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    LazySegTree lst(a);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            cout << lst.query(l - 1, r) << endl;
        }
        else if (op == 2) {
            int l, r, x; cin >> l >> r >> x;
            lst.update(l - 1, r, x);
        }
        else {
            int i, v; cin >> i >> v;
            lst.set(i - 1, v);
        }
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