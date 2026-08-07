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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node {
    int t, o, c;
};

struct SegTree {
    int size;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        int matches = min(left.o, right.c);
        return {
            left.t + right.t + 2 * matches,
            left.o + right.o - matches,
            left.c + right.c - matches
        };
    }

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, {0, 0, 0});
    }

    void set(int i, char ch, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (ch == '(') {
                tree[x] = {0, 1, 0};
            }
            else {
                tree[x] = {0, 0, 1};
            }
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, ch, 2 * x + 1, lx, mid);
        }
        else {
            set(i, ch, 2 * x + 2, mid, rx);
        }

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(int i, char ch) {
        set(i, ch, 0, 0, size);
    }

    Node query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or  l >= rx) return {0, 0, 0};
        if (lx >= l and rx <= r) return tree[x];

        int mid = (lx + rx) / 2;
        Node res1 = query(l, r, 2 * x + 1, lx, mid);
        Node res2 = query(l, r, 2 * x + 2, mid, rx);

        return merge(res1, res2);
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, size).t;
    }
};

void solve() {
    str s; cin >> s;
    int n = (int) s.size();

    SegTree st;
    st.init(n);
    for (int i = 0; i < n; ++i) {
        st.set(i, s[i]);
    }

    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        cout << st.query(l - 1, r) << endl;
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