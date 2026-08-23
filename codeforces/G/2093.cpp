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

struct XorTrie {
    static const int BITS = 30; // [CORE] Use 30 for numbers <= 10^9, 62 for long long <= 10^18

    struct Node {
        int nxt[2];
        int idx; // [CORE] Number of integers sharing this bit-prefix
        Node() { nxt[0] = nxt[1] = idx = -1; }
    };

    vector<Node> tree;
    int ptr = 0;

    XorTrie(int max_nodes = 1) { tree.resize(max_nodes); clear(); }

    void clear() { ptr = 0; newNode(); }

    int newNode() { tree[ptr] = Node(); return ptr++; }

    void insert(int x, int idx) {
        int u = 0;
        tree[0].idx = max(tree[0].idx, idx);
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (tree[u].nxt[bit] == -1) tree[u].nxt[bit] = newNode();
            u = tree[u].nxt[bit];
            tree[u].idx = max(tree[u].idx, idx);
        }
    }

    // [CORE] Returns count of y in Trie such that (x ^ y) >= k
    int get_max_index(int x, int k) {
        int u = 0;
        int res = -1;
        for (int position = BITS - 1; position >= 0; --position) {
            int xBit = (x >> position) & 1;
            int kBit = (k >> position) & 1;
            if (kBit == 1) {
                int wanted = xBit ^ 1;
                if (~tree[u].nxt[wanted]) {
                    u = tree[u].nxt[wanted];
                }
                else {
                    return res;
                }
            }
            else {
                int one = xBit ^ 1;
                if (~tree[u].nxt[one]) {
                    res = max(res, tree[tree[u].nxt[one]].idx);
                }
                
                int zero = xBit;
                if (~tree[u].nxt[zero]) {
                    u = tree[u].nxt[zero];
                }
                else {
                    return res;
                }
            }
        }
        res = max(res, tree[u].idx);
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    XorTrie xt(n * 31 + 5);
    int mn = n + 1;
    for (int i = 0; i < n; ++i) {
        xt.insert(a[i], i);
        int temp = xt.get_max_index(a[i], k);
        if (~temp) {
            mn = min(mn, i - temp + 1);
        }
    }
    cout << (mn == n + 1 ? -1 : mn) << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}