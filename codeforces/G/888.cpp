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
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

inline void DEBUG(const int & n);
struct XorTrie {
    static const int BITS = 30;

    struct Node {
        int nxt[2];
        int pass;
        Node() { nxt[0] = nxt[1] = -1; pass = 0; }
    };

    vector<Node> tree;
    int ptr = 0;

    XorTrie(int max_nodes = 3200005) { tree.resize(max_nodes); clear(); }

    void clear() { ptr = 0; newNode(); }

    int newNode() { tree[ptr] = Node(); return ptr++; }

    void insert(int x) {
        int u = 0; tree[0].pass++;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (tree[u].nxt[bit] == -1) tree[u].nxt[bit] = newNode();
            u = tree[u].nxt[bit]; tree[u].pass++;
        }
    }

    void erase(int x) {
        if (tree[0].pass == 0) return;
        int u = 0; tree[0].pass--;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            u = tree[u].nxt[bit]; 
            tree[u].pass--;
        }
    }

    bool has_child(int u, int b) const {
        return u != -1 && tree[u].nxt[b] != -1 && tree[tree[u].nxt[b]].pass > 0;
    }
};

struct XorTrieHelper {
    int minXor;
    int val1;
    int val2;

    bool operator<(const XorTrieHelper& other) const {
        if (minXor != other.minXor) return minXor < other.minXor;
        if (val1 != other.val1)     return val1 < other.val1;
        return val2 < other.val2;
    }
};

XorTrieHelper getMinXorPair(const XorTrie & t1, int u1,
                            const XorTrie & t2, int u2,
                            int bit = XorTrie::BITS - 1,
                            int v1 = 0, int v2 = 0) {
    if (t1.tree[0].pass == 0 or t2.tree[0].pass == 0) {
        return {INT_MAX, -1, -1};
    }
    if (bit < 0) {
        return {0, v1, v2};
    }

    XorTrieHelper best{INT_MAX, -1, -1};
    if (t1.has_child(u1, 0) and t2.has_child(u2, 0)) {
        best = min(best, getMinXorPair(t1, t1.tree[u1].nxt[0], 
                                        t2, t2.tree[u2].nxt[0], 
                                        bit - 1, v1, v2));
    }
    if (t1.has_child(u1, 1) and t2.has_child(u2, 1)) {
        best = min(best, getMinXorPair(t1, t1.tree[u1].nxt[1], 
                                        t2, t2.tree[u2].nxt[1], 
                                        bit - 1, v1 | (1 << bit), v2 | (1 << bit)));
    }

    if (best.minXor != INT_MAX) return best;

    if (t1.has_child(u1, 0) and t2.has_child(u2, 1)) {
        XorTrieHelper res = getMinXorPair(t1, t1.tree[u1].nxt[0], 
                                          t2, t2.tree[u2].nxt[1], 
                                          bit - 1, v1, v2 | (1 << bit));
        res.minXor |= (1 << bit);
        best = min(best, res);
    }
    if (t1.has_child(u1, 1) and t2.has_child(u2, 0)) {
        XorTrieHelper res = getMinXorPair(t1, t1.tree[u1].nxt[1], 
                                          t2, t2.tree[u2].nxt[0], 
                                          bit - 1, v1 | (1 << bit), v2);
        res.minXor |= (1 << bit);
        best = min(best, res);
    }

    return best;
}

long long ans = 0;
void moveMinEle(XorTrie& t1, XorTrie& t2) {
    XorTrieHelper temp = getMinXorPair(t1, 0, t2, 0);
    
    if (temp.minXor != INT_MAX) {
        ans += (temp.val1 ^ temp.val2);
        t2.erase(temp.val2);
        t1.insert(temp.val2);
    }
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // DEBUG(n);
    XorTrie xt, xt2;
    xt2.insert(a[1]);
    for (int i = 2; i <= n; ++i) {
        xt.insert(a[i]);
    }
    for (int i = 2; i <= n; ++i) {
        moveMinEle(xt2, xt);
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
    
    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}

inline void DEBUG(const int & n) {
    for (int i = 1; i <= n; ++i) {
        cout << "\t" << i;
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << "\t";
        for (int j = 1; j <= n; ++j) {
            cout << (i ^ j) << "\t\n"[j == n];
        }
    }
}