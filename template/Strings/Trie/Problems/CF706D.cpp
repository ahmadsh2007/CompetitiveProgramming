/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

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

// Macro to generate a random integer between l and r (inclusive)
// To use: `ll my_random_number = rnd(1, 100);` or `int random_index = rnd(0, my_vector.size() - 1);`
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<ll>(l, r)(rng)

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct XorTrie {
    static const int BITS = 32;

    struct Node {
        int nxt[2];
        int pass;
        Node() { nxt[0] = nxt[1] = -1; pass = 0; }
    };

    vector<Node> tree;
    int ptr = 0;

    XorTrie(int max_nodes = 6500005) { tree.resize(max_nodes); clear(); }

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

    int get_max_xor(int x) {
        if (tree[0].pass == 0) return 0;
        int u = 0, max_xor = 0;
        for (int i = BITS - 1; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit;
            
            if (tree[u].nxt[want] != -1 && tree[tree[u].nxt[want]].pass > 0) {
                max_xor |= (1 << i);
                u = tree[u].nxt[want];
            } else {
                u = tree[u].nxt[bit];
            }
        }
        return max_xor;
    }
};

void solve() {
    int q; cin >> q;
    XorTrie trie;
    trie.insert(0);
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+') trie.insert(x);
        else if (c == '-') trie.erase(x);
        else cout << trie.get_max_xor(x) << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
    solve();
    return 0;
}