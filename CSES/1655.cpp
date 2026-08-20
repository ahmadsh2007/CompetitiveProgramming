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
        int pass; // [CORE] Number of integers sharing this bit-prefix
        Node() { nxt[0] = nxt[1] = -1; pass = 0; }
    };

    vector<Node> tree;
    int ptr = 0;

    XorTrie(int max_nodes = 5000005) { tree.resize(max_nodes); clear(); }

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

    // If you want to erase the number you xor with...
    // add tree[0].pass--; at the begining of the fucntion before int u and...
    // add tree[u].pass--; at the end of the for loop
    // [CORE] Returns the maximum possible value of (x ^ y) for all y currently in Trie
    int get_max_xor(int x) {
        if (tree[0].pass == 0) return 0; // Empty Trie safety
        // tree[0].pass--;
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
            // tree[u].pass--;
        }
        return max_xor;
    }

    // [OPTIONAL] Returns the minimum possible value of (x ^ y) for all y currently in Trie
    int get_min_xor(int x) {
        if (tree[0].pass == 0) return 0; // Empty Trie safety
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
        }
        return min_xor;
    }

    // [CORE] Returns count of y in Trie such that (x ^ y) >= k
    int count_greater_equal(int x, int k) {
        if (tree[0].pass == 0) return 0; // Empty Trie safety
        
        int u = 0, count = 0;
        
        for (int i = BITS - 1; i >= 0; i--) {
            if (u == -1) break; // Dead end, no more paths to check
            
            int bit_x = (x >> i) & 1;
            int bit_k = (k >> i) & 1;
            
            if (bit_k == 1) {
                // The XOR MUST be 1 here to keep up with k.
                // We have no choice but to go down the opposite bit path.
                u = tree[u].nxt[1 - bit_x];
            } else {
                // bit_k is 0. 
                // Path 1: If we get a 1, it's STRICTLY GREATER than k. 
                // All elements in this subtree are valid! Add them all.
                if (tree[u].nxt[1 - bit_x] != -1) {
                    count += tree[tree[u].nxt[1 - bit_x]].pass;
                }
                
                // Path 2: We get a 0, which matches k. 
                // We must keep traversing down to check the lower bits.
                u = tree[u].nxt[bit_x];
            }
        }
        
        // If we finish the loop and haven't fallen off the Trie,
        // the remaining elements at this node have an XOR sum EXACTLY equal to k.
        if (u != -1) {
            count += tree[u].pass;
        }
        
        return count;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    XorTrie xt;
    for (auto &x : a) {
        cin >> x;
    }
    
    vector<int> prefix(n);
    prefix[0] = a[0];
    xt.insert(0);
    int mx = a[0];
    for (int i = 0; i < n; ++i) {
        if (i) prefix[i] = prefix[i - 1] ^ a[i];
        xt.insert(prefix[i]);
        mx = max(mx, xt.get_max_xor(prefix[i]));
    }

    cout << mx << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}