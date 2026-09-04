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
#define int long long
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

struct XorTrie {
    static const int BITS = 30;

    struct Node {
        int nxt[2];
        int l, r;
        Node() { 
            nxt[0] = nxt[1] = -1; 
            l = 1e9; 
            r = -1; 
        }
    };

    vector<Node> tree;
    int ptr = 0;

    XorTrie(int max_nodes = 6000005) { tree.resize(max_nodes); clear(); }

    void clear() { ptr = 0; newNode(); }

    int newNode() { tree[ptr] = Node(); return ptr++; }

    void insert(int x, int idx) {
        int u = 0;
        tree[u].l = min(tree[u].l, idx);
        tree[u].r = max(tree[u].r, idx);
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (tree[u].nxt[bit] == -1) tree[u].nxt[bit] = newNode();
            u = tree[u].nxt[bit];
            tree[u].l = min(tree[u].l, idx);
            tree[u].r = max(tree[u].r, idx);
        }
    }

    int query_min_xor(int u, int val, int bit) {
        int res = 0;
        for (int i = bit; i >= 0; i--) {
            int b = (val >> i) & 1;
            if (tree[u].nxt[b] != -1) {
                u = tree[u].nxt[b];
            } else {
                res |= (1LL << i);
                u = tree[u].nxt[1 - b];
            }
        }
        return res;
    }

    int solve_mst(int u, int bit, const vector<int>& a) {
        if (bit < 0 or u == -1) return 0;

        int left = tree[u].nxt[0];
        int right = tree[u].nxt[1];

        if (left != -1 and right != -1) {
            int minBridge = INF;
            for (int i = tree[left].l; i <= tree[left].r; ++i) {
                minBridge = min(minBridge, (1LL << bit) | query_min_xor(right, a[i], bit - 1));
            }
            return minBridge + solve_mst(left, bit - 1, a) + solve_mst(right, bit - 1, a);
        }

        if (left != -1) return solve_mst(left, bit - 1, a);
        if (right != -1) return solve_mst(right, bit - 1, a);

        return 0;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    cin >> a;

    sort(all(a));
    a.erase(unique(all(a)), a.end());

    XorTrie xt;
    for (int i = 0; i < (int)a.size(); ++i) {
        xt.insert(a[i], i);
    }

    int ans = xt.solve_mst(0, XorTrie::BITS - 1, a);
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