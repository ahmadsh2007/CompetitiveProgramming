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

    bool insert(const string& s) {
        bool createdNewNode = false;
        int u = 0; tree[0].pass++;
        for (char ch : s) {
            int c = ch - BASE;
            if (tree[u].nxt[c] == -1) {
                tree[u].nxt[c] = newNode();
                createdNewNode = true;
            }
            u = tree[u].nxt[c]; tree[u].pass++;
        }
        tree[u].end++;
        return createdNewNode;
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

void solve() {
    str s; cin >> s;
    str t; cin >> t;
    int k; cin >> k;

    int n = (int) s.size();
    StringTrie trie(2000005);
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int u = 0;
        int badCnt = 0;
        for (int j = i; j < n; ++j) {
            if (t[s[j] - 'a'] == '0') badCnt++;
            
            if (badCnt > k) break;

            int c = s[j] - 'a';
            if (trie.tree[u].nxt[c] == -1) {
                trie.tree[u].nxt[c] = trie.newNode();
                ans++;
            }

            u = trie.tree[u].nxt[c];
        }
    }

    cout << ans << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}