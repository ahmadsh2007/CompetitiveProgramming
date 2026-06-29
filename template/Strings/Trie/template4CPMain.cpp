#include <bits/stdc++.h>
using namespace std;

#include "template4CP.h"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    // Initialize with enough nodes for the entire problem constraints
    Trie trie(200005);

    auto print_header = [](string title) {
        cout << "\n========================================\n";
        cout << "  " << title << "\n";
        cout << "========================================\n";
    };

    // ---------------------------------------------------------
    // TEST 1: Heavy Insertion & Duplicate Handling
    // ---------------------------------------------------------
    print_header("TEST 1: Insertion & Duplicates");
    vector<string> corpus = {"apple", "app", "application", "apt", "bat", "bat", "batch"};
    
    for (string s : corpus) {
        trie.insert(s);
        cout << "Inserted: \"" << s << "\" | Total words in Trie: " << trie.tree[0].pass << "\n";
    }

    // ---------------------------------------------------------
    // TEST 2: Exact Search vs. Prefix Counting
    // ---------------------------------------------------------
    print_header("TEST 2: Exact Search & Prefix Counts");
    vector<string> queries = {"app", "appl", "apple", "ap", "batch", "batman", "zookeeper"};

    for (string q : queries) {
        bool found = trie.search(q);
        int p_cnt = trie.count_prefix(q);
        cout << "Query: \"" << left << setw(10) << q << "\" | Exact Match: " << (found ? "YES" : "NO ") 
             << " | Prefix Count: " << p_cnt << "\n";
    }

    // ---------------------------------------------------------
    // TEST 3: Lexicographical K-th Queries
    // ---------------------------------------------------------
    print_header("TEST 3: K-th Lexicographical Strings");
    int total_words = trie.tree[0].pass;
    
    // Test out of bounds (0 and Total+1), plus every valid index
    for (int k = 0; k <= total_words + 1; k++) {
        string res = trie.get_kth(k);
        cout << "k = " << k << ": \"" << (res == "" ? "[OUT OF BOUNDS]" : res) << "\"\n";
    }

    // ---------------------------------------------------------
    // TEST 4: Deletion & Ghost Node Verification
    // ---------------------------------------------------------
    print_header("TEST 4: Deletions & Sibling Preservation");
    vector<string> to_delete = {"bat", "apple", "nonexistent"};

    for (string d : to_delete) {
        bool erased = trie.erase(d);
        cout << "Attempting to erase \"" << left << setw(11) << d << "\"... Status: " << (erased ? "SUCCESS" : "FAILED (Not Found)") << "\n";
    }

    cout << "\n--- State After Deletions ---\n";
    cout << "Search \"bat\" (Should be TRUE because we inserted it twice): " << (trie.search("bat") ? "YES" : "NO") << "\n";
    trie.erase("bat"); // Delete the second instance
    cout << "Search \"bat\" (After 2nd deletion, should be NO):          " << (trie.search("bat") ? "YES" : "NO") << "\n";
    cout << "Search \"batch\" (Sibling of 'bat', must still exist):      " << (trie.search("batch") ? "YES" : "NO") << "\n";
    cout << "Prefix count for \"ap\" (Should drop from 3 to 2):          " << trie.count_prefix("ap") << "\n";

    // ---------------------------------------------------------
    // TEST 5: Multi-Testcase Simulation (clear() verification)
    // ---------------------------------------------------------
    print_header("TEST 5: Multi-Testcase clear() Verification");
    cout << "Memory allocated (vector size): " << trie.tree.size() << " nodes.\n";
    cout << "Active nodes (ptr value):       " << trie.ptr << " nodes used.\n";
    
    trie.clear(); // O(1) Instant Reset
    
    cout << "\nAfter clear():\n";
    cout << "Active nodes (ptr value):       " << trie.ptr << " node (Root only).\n";
    cout << "Total words after clear():      " << trie.tree[0].pass << "\n";
    cout << "Search \"application\":           " << (trie.search("application") ? "YES" : "NO") << "\n";

    trie.insert("codeforces");
    cout << "Inserted \"codeforces\" into fresh Trie. Found: " << (trie.search("codeforces") ? "YES" : "NO") << "\n";

    // ---------------------------------------------------------
    // TEST 6: XOR Trie Conversion & Maximum XOR Verification
    // ---------------------------------------------------------
    print_header("TEST 6: Bitwise XOR Trie Verification");
    
    // To test XOR, we must simulate a fresh binary Trie (K=2)
    // We instantiate a separate Trie, but in a contest, you'd just change K=2 at the top.
    struct XorTestTrie {
        struct Node { int nxt[2]; int pass; Node() { nxt[0] = nxt[1] = -1; pass = 0; } };
        vector<Node> tree; int ptr = 0;
        XorTestTrie() { tree.resize(1000); clear(); }
        void clear() { ptr = 0; tree[ptr++] = Node(); }
        void insert(const string& s) {
            int u = 0; tree[0].pass++;
            for (char ch : s) {
                int bit = ch - '0';
                if (tree[u].nxt[bit] == -1) { tree[u].nxt[bit] = ptr; tree[ptr++] = Node(); }
                u = tree[u].nxt[bit]; tree[u].pass++;
            }
        }
        int get_max_xor(const string& s) {
            int u = 0, max_xor = 0;
            for (int i = 0; i < (int)s.size(); i++) {
                int bit = s[i] - '0', want = 1 - bit;
                if (tree[u].nxt[want] != -1 && tree[tree[u].nxt[want]].pass > 0) {
                    max_xor |= (1 << ((int)s.size() - 1 - i));
                    u = tree[u].nxt[want];
                } else u = tree[u].nxt[bit];
            }
            return max_xor;
        }
    } xor_trie;

    // Helper to convert integer to 5-bit binary string (using 5 bits for easy visual check)
    auto to_bin = [](int x) { return bitset<5>(x).to_string(); };

    vector<int> nums = {3, 10, 5, 25, 2}; // Binary: 00011, 01010, 00101, 11001, 00010
    cout << "Inserting numbers into XOR Trie: ";
    for (int n : nums) { cout << n << " "; xor_trie.insert(to_bin(n)); }
    cout << "\n\n";

    // Querying max XOR against the inserted numbers
    int query_val = 8; // Binary: 01000
    // Best match for 8 (01000) is 25 (11001) -> 8 ^ 25 = 17
    // Wait, let's check: 8 ^ 25 = 17. What about 8 ^ 3 = 11. 8 ^ 5 = 13. 8 ^ 2 = 10.
    // Actually, 8 (01000) ^ 25 (11001) = 17. 
    int ans = xor_trie.get_max_xor(to_bin(query_val));
    cout << "Max XOR for query " << query_val << " (Binary: " << to_bin(query_val) << "):\n";
    cout << "Result: " << ans << " (Expected: 17, since 8 ^ 25 = 17)\n";

    return 0;
}