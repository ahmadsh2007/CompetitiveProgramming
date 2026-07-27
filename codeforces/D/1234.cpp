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
    vector<int> mask;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        mask.assign(2 * size, 0);
    }

    void set(int i, char c, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mask[x] = (1 << (c - 'a'));
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, c, 2 * x + 1, lx, mid);
        }
        else {
            set(i, c, 2 * x + 2, mid, rx);
        }
        mask[x] = mask[2 * x + 1] | mask[2 * x + 2];
    }
    void set(int i, char c) {
        return set(i, c, 0, 0, size);
    }

    int getUnique(int l, int r, int x, int lx, int rx) {
        if (r <= lx or rx <= l) return 0;
        if (lx >= l and rx <= r) return mask[x];

        int mid = (lx + rx) / 2;
        int m1 = getUnique(l, r, 2 * x + 1, lx, mid);
        int m2 = getUnique(l, r, 2 * x + 2, mid, rx);

        return m1 | m2;
    }
    int getUnique(int l, int r) {
        int m = getUnique(l, r, 0, 0, size);
        return __builtin_popcount(m);
    }
};

void solve() {
    str s; cin >> s;
    int n = (int) s.size();

    SegTree st;
    st.init(n + 1);

    for (int i = 1; i <= n; ++i) {
        st.set(i, s[i - 1]);
    }

    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            st.set(pos, c);
        }
        else {
            int l, r; cin >> l >> r;
            cout << st.getUnique(l, r + 1) << endl;
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