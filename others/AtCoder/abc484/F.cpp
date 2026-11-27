/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

template<class T>istream& operator>>(istream& in, vector<T>& v){for(auto& x:v) in>>x;return in;}
template<class T>ostream& operator<<(ostream& out, vector<T>& v){for(auto& x:v) out<<x<<' ';return out;}

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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const long long INF = 1e18;
const int MOD = 1e9 + 7;

struct SegTree {
    int size;
    vector<int> tree;

    SegTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    int merge(int a, int b) {
        if (a == -2 or b == -2) return -2;
        if (a == 0) return b;
        if (b == 0) return a;
        return a == b ? a : -2;
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = (v == -1 ? 0 : v);
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 0;
        if (lx >= l and rx <= r) {
            return tree[x];
        }

        int mid = lx + (rx - lx) / 2;
        int s1 = query(l, r, 2 * x + 1, lx, mid);
        int s2 = query(l, r, 2 * x + 2, mid, rx);

        return merge(s1, s2);
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    SegTree st(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        st.set(i, x);
    }


    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int i, x; cin >> i >> x;
            st.set(i, x);
        }
        else {
            int l, r; cin >> l >> r;
            cout << (st.query(l, r + 1) != -2 ? "Yes" : "No") << endl;
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