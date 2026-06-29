#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// STRING TRIE TEMPLATE (Prefixes, Lexicographical K-th, Word Counting)
// ============================================================================
struct StringTrie {
    static const int K = 26; 
    static const char BASE = 'a'; // [CORE] 'a' for lowercase, 'A' for uppercase

    struct Node {
        int nxt[K];
        int pass; // [CORE] Number of words sharing this exact prefix
        int end;  // [CORE] Number of words ending exactly at this node
        Node() { memset(nxt, -1, sizeof(nxt)); pass = end = 0; }
    };

    vector<Node> tree;
    int ptr = 0; 

    StringTrie(int max_nodes = 200005) { tree.resize(max_nodes); clear(); }

    void clear() { ptr = 0; newNode(); }

    int newNode() { tree[ptr] = Node(); return ptr++; }

    void insert(const string& s) {
        int u = 0; tree[0].pass++;
        for (char ch : s) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1) tree[u].nxt[c] = newNode();
            u = tree[u].nxt[c]; tree[u].pass++;
        }
        tree[u].end++;
    }

    bool search(const string& s) {
        int u = 0;
        for (char ch : s) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1 || tree[tree[u].nxt[c]].pass == 0) return false;
            u = tree[u].nxt[c];
        }
        return tree[u].end > 0;
    }

    int count_prefix(const string& pre) {
        int u = 0;
        for (char ch : pre) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1 || tree[tree[u].nxt[c]].pass == 0) return 0;
            u = tree[u].nxt[c];
        }
        return tree[u].pass;
    }

    bool erase(const string& s) {
        if (!search(s)) return false;
        int u = 0; tree[0].pass--; 
        for (char ch : s) { 
            u = tree[u].nxt[ch - BASE]; 
            tree[u].pass--; 
        }
        tree[u].end--; return true;
    }

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
};