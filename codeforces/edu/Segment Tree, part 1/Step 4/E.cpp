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

struct SegTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 1e9 + 7);
    }

    void set(int i, int h, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = h;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, h, 2 * x + 1, lx, mid);
        }
        else {
            set(i, h, 2 * x + 2, mid, rx);
        }

        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, int h) {
        set(i, h, 0, 0, size);
    }

    int updateRange(int l, int r, int p, int x, int lx, int rx) {
        if (lx >= r or  rx <= l or tree[x] > p or tree[x] == 0) return 0ll;
        if (rx - lx == 1) {
            tree[x] = 1e9 + 7;
            return 1;
        }

        int mid = (lx + rx) / 2;
        int s1 = updateRange(l, r, p, 2 * x + 1, lx, mid);
        int s2 = updateRange(l, r, p, 2 * x + 2, mid, rx);

        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
        return s1 + s2;
    }
    int updateRange(int l, int r, int p) {
        return updateRange(l, r, p, 0, 0, size);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    SegTree st;
    st.init(n);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int i, h; cin >> i >> h;
            st.set(i, h);
        }
        else {
            int l, r, p; cin >> l >> r >> p;
            cout << st.updateRange(l, r, p) << endl;
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