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
    int op;
    int mn;
};

struct SegTree {
    int size;
    vector<Node> tree;

    SegTree(int n) {
        size = 1;
        while (size < n) {
            size <<= 1;
        }
        tree.assign(2 * size, {-1, 0});
    }

    void set(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return;
        if (lx >= l and rx <= r) {
            tree[x].op = v;
            tree[x].mn = v;
            return;
        }
        
        if (~tree[x].op and rx - lx > 1) {
            tree[2 * x + 1].mn = tree[2 * x + 1].op = tree[x].op;
            tree[2 * x + 2].mn = tree[2 * x + 2].op = tree[x].op;
            tree[x].op = -1;
        }

        int mid = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, mid);
        set(l, r, v, 2 * x + 2, mid, rx);
        tree[x].mn = min(tree[2 * x + 1].mn, tree[2 * x + 2].mn);
    }
    void set(int l, int r, int v) {
        set(l, r, v, 0, 0, size);
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (l >= rx or r <= lx) return LLONG_MAX;
        if (rx <= r and lx >= l) {
            return tree[x].mn;
        }

        if (~tree[x].op and rx - lx > 1) {
            tree[2 * x + 1].mn = tree[2 * x + 1].op = tree[x].op;
            tree[2 * x + 2].mn = tree[2 * x + 2].op = tree[x].op;
            tree[x].op = -1;
        }

        int mid = (lx + rx) / 2;
        int m1 = get(l, r, 2 * x + 1, lx, mid);
        int m2 = get(l, r, 2 * x + 2, mid, rx);

        return min(m1, m2);
    }
    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};

void solve() {
    int n, m; cin >> n >> m;

    SegTree st(n);
    while(m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, v; cin >> l >> r >> v;
            st.set(l, r, v);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.get(l, r) << endl;
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