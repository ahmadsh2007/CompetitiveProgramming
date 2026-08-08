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
    vector<int> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        tree[x] = gcd(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int Query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or rx <= l) return 0;
        if (l <= lx and rx <= r) return tree[x];

        int mid = (lx + rx) / 2;
        return gcd(Query(l, r, 2 * x + 1, lx, mid), Query(l, r, 2 * x + 2, mid, rx));
    }
    int Query(int l, int r) {
        return Query(l, r, 0, 0, size);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    SegTree st;
    st.init(n);

    for (int i = 1; i < n; ++i) {
        st.set(i, abs(a[i] - a[i + 1]));
    }
    
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.Query(l, r) << " \n"[q == 0];
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