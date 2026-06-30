/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

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
        int pass; // [CORE] Number of integers sharing this bit-prefix
        Node() { nxt[0] = nxt[1] = -1; pass = 0; }
    };

    vector<Node> tree;
    int ptr = 0;

    XorTrie(int max_nodes = 6000005) { tree.resize(max_nodes); clear(); }

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
        int u = 0; tree[0].pass--;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            u = tree[u].nxt[bit]; tree[u].pass--;
        }
    }

    // [CORE] Returns the maximum possible value of (x ^ y) for all y currently in Trie
    int get_max_xor(int x) {
        if (tree[0].pass == 0) return 0; // Empty Trie safety
        int u = 0, max_xor = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit; // Greedily want the opposite bit to maximize XOR
            
            if (tree[u].nxt[want] != -1 && tree[tree[u].nxt[want]].pass > 0) {
                max_xor |= (1 << i);
                u = tree[u].nxt[want];
            } else {
                u = tree[u].nxt[bit];
            }
        }
        return max_xor;
    }

    // [OPTIONAL] Returns the minimum possible value of (x ^ y) for all y currently in Trie
    int get_min_xor(int x) {
        if (tree[0].pass == 0) return 0; // Empty Trie safety
        tree[0].pass--;
        int u = 0, min_xor = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = bit; // Greedily want the opposite bit to maximize XOR
            if (tree[u].nxt[want] != -1 && tree[tree[u].nxt[want]].pass > 0) {
                u = tree[u].nxt[want];
            } else {
                min_xor |= (1 << i);
                u = tree[u].nxt[1 - bit];
            }
            tree[u].pass--;
        }
        return min_xor;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> p(n);
    for (auto &x : a) cin >> x;
    for (auto &x : p) cin >> x;

    XorTrie trie;
    for (auto &x : p) trie.insert(x);

    for (int i = 0; i < n; ++i) {
        cout << trie.get_min_xor(a[i]) << " \n"[i == n - 1];
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}