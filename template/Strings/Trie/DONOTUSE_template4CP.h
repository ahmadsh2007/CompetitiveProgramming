#include <bits/stdc++.h>
using namespace std;

struct Trie {
    // [CORE] Alphabet size: 26 for ('a'-'z'), 2 for XOR Trie binary bits
    static const int K = 26; 
    static const char BASE = 'a'; // [CORE] 'a' for lower, 'A' for upper, '0' for XOR

    struct Node {
        int nxt[K];
        int pass; // [CORE] Number of words sharing this exact prefix
        int end;  // [CORE] Number of words ending exactly at this node
        Node() { memset(nxt, -1, sizeof(nxt)); pass = end = 0; }
    };

    vector<Node> tree;
    int ptr = 0; // [CORE] Flat memory allocator pointer

    // [CORE] Pre-allocate to prevent vector doubling lag (2e5 nodes ~= 22MB RAM)
    Trie(int max_nodes = 200005) { tree.resize(max_nodes); clear(); }

    // [CORE] O(1) Instant Reset. Call inside "while(T--)" multi-test loops!
    void clear() { ptr = 0; newNode(); }

    int newNode() { tree[ptr] = Node(); return ptr++; }

    // [CORE] Insert string in O(L). For XOR Trie, pass binary string of numbers.
    void insert(const string& s) {
        int u = 0; tree[0].pass++;
        for (char ch : s) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1) tree[u].nxt[c] = newNode();
            u = tree[u].nxt[c]; tree[u].pass++;
        }
        tree[u].end++;
    }

    // [OPTIONAL] Returns true if exact word 's' exists
    bool search(const string& s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1 || tree[tree[u].nxt[c]].pass == 0) return false;
            u = tree[u].nxt[c];
        }
        return tree[u].end > 0;
    }

    // [OPTIONAL] Returns count of inserted words starting with prefix 'pre'
    int count_prefix(const string& pre) {
        int u = 0;
        for (char ch : pre) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1 || tree[tree[u].nxt[c]].pass == 0) return 0;
            u = tree[u].nxt[c];
        }
        return tree[u].pass;
    }

    // [OPTIONAL] Erases ONE instance of word 's'. Returns false if not found.
    bool erase(const string& s) {
        if (!search(s)) return false;
        int u = 0; tree[0].pass--; // <--- decrements root
        for (char ch : s) { 
            u = tree[u].nxt[ch - BASE]; 
            tree[u].pass--; // <--- decrements path
        }
        tree[u].end--; 
        return true;
    }

    // [OPTIONAL] Returns 1-indexed K-th lexicographical word in O(L)
    string get_kth(int k) {
        if (k <= 0 || k > tree[0].pass) return "";
        int u = 0; string res = "";
        while (true) {
            if (tree[u].end >= k) return res;
            k -= tree[u].end;
            for (int c = 0; c < K; c++) {
                int nxt = tree[u].nxt[c];
                if (nxt != -1 && tree[nxt].pass > 0) {
                    if (k <= tree[nxt].pass) { res += char(BASE+c); u = nxt; break; }
                    else k -= tree[nxt].pass;
                }
            }
        }
        return res;
    }

    // [OPTIONAL - XOR TRIE ONLY] Returns max possible (x ^ val) in O(log(val))
    // REQUIRES: K = 2, and numbers inserted as 30-bit binary strings ("01101...")
    int get_max_xor(const string& binary_x) {
        int u = 0, max_xor = 0;
        for (int i = 0; i < (int)binary_x.size(); i++) {
            int bit = binary_x[i] - '0';
            int want = 1 - bit; // Greedily want opposite bit to maximize XOR
            if (tree[u].nxt[want] != -1 && tree[tree[u].nxt[want]].pass > 0) {
                max_xor |= (1 << ((int)binary_x.size() - 1 - i));
                u = tree[u].nxt[want];
            } else {
                u = tree[u].nxt[bit];
            }
        }
        return max_xor;
    }

    // [OPTIONAL - FOR LOCAL DEBUGGING ONLY] Delete before submitting to Codeforces!
    void debug_print(int u = 0, string cur = "") {
        if (tree[u].end > 0) cout << cur << " (count: " << tree[u].end << ")\n";
        for (int c = 0; c < K; c++) {
            if (tree[u].nxt[c] != -1 && tree[tree[u].nxt[c]].pass > 0) {
                debug_print(tree[u].nxt[c], cur + char('a' + c));
            }
        }
    }
};