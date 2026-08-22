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
    char first = 0;
    char last = 0;
    bool alter = true;
    int mask = 0;
    bool tagged = false;
    bool empty = true;

    Node operator+(const Node & n) const {
        if (this->empty) return n;
        if (n.empty) return *this;

        Node temp;
        temp.empty = false;
        temp.first = this->first;
        temp.last = n.last;
        temp.mask = this->mask | n.mask;
        
        int distinct = __builtin_popcount(temp.mask);
        temp.alter = (distinct <= 2 and this->last != n.first and this->alter and n.alter);
        temp.tagged = false;

        return temp;
    }
};

struct LazySegTree {
    int size;
    vector<Node> tree;
    LazySegTree(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        tree.assign(2 * size, {});
    }
    
    void apply(int x, int lx, int rx, char c) {
        tree[x].tagged = true;
        tree[x].empty = false;
        tree[x].first = tree[x].last = c;
        tree[x].mask = (1 << (c - 'a'));
        tree[x].alter = (rx - lx == 1);
    }

    void push(int x, int lx, int rx) {
        if (tree[x].tagged and rx - lx > 1) {
            int mid = (lx + rx) / 2;
            apply(2 * x + 1, lx, mid, tree[x].first);
            apply(2 * x + 2, mid, rx, tree[x].first);
            tree[x].tagged = false;
        }
    }
    
    void pull(int x) {
        bool tag = tree[x].tagged;
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        tree[x].tagged = tag;
    }

    void set(int i, char c, int x, int lx, int rx) {
        if (rx - lx == 1) {
            apply(x, lx, rx, c);
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, c, 2 * x + 1, lx, mid);
        }
        else {
            set(i, c, 2 * x + 2, mid, rx);
        }

        pull(x);
    }
    void set(int i, char c) {
        set(i, c, 0, 0, size);
    }

    void update(int l, int r, char c, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return;
        if (rx <= r and lx >= l) {
            apply(x, lx, rx, c);
            return;
        }

        push(x, lx, rx);
        
        int mid = (lx + rx) / 2;
        update(l, r, c, 2 * x + 1, lx, mid);
        update(l, r, c, 2 * x + 2, mid, rx);

        pull(x);
    }
    void update(int l, int r, char c) {
        update(l, r, c, 0, 0, size);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return Node();
        if (rx <= r and lx >= l) {
            return tree[x];
        }

        push(x, lx, rx);
        pull(x);

        int mid = (lx + rx) / 2;
        Node n1 = query(l, r, 2 * x + 1, lx, mid);
        Node n2 = query(l, r, 2 * x + 2, mid, rx);

        return n1 + n2;
    }
    bool query(int l, int r) {
        return query(l, r, 0, 0, size).alter;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
    
    LazySegTree lst(n + 1);
    for (int i = 1; i <= n; ++i) {
        lst.set(i, s[i]);
    }

    while (q--) {
        str op; cin >> op;
        if (op == "SET") {
            int l, r; char c; cin >> l >> r >> c;
            lst.update(l, r + 1, c);
        }
        else {
            int l, r; cin >> l >> r;
            cout << (lst.query(l, r + 1) or (r == l) ? "YES\n" : "NO\n");
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