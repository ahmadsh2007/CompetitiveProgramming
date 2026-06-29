#include <bits/stdc++.h>
using namespace std;

#include "StringTrieTemplate.h"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    StringTrie trie(100005);

    auto print_header = [](string title) {
        cout << "\n========================================\n  " << title << "\n========================================\n";
    };

    print_header("STRING TRIE: Insertion & Search");
    vector<string> words = {"codeforces", "coder", "coding", "contest", "leeking"};
    for (const string& w : words) trie.insert(w);

    cout << "Search 'codeforces': " << (trie.search("codeforces") ? "PASSED" : "FAILED") << "\n";
    cout << "Search 'cod':        " << (!trie.search("cod") ? "PASSED (Prefix strictly)" : "FAILED") << "\n";
    cout << "Prefix count 'cod':  " << trie.count_prefix("cod") << " (Expected: 3)\n";

    print_header("STRING TRIE: Deletion & Lexicographical Order");
    cout << "2nd Alphabetical Word: " << trie.get_kth(2) << " (Expected: coder)\n";
    
    trie.erase("coder");
    cout << "Erased 'coder'. New 2nd Word: " << trie.get_kth(2) << " (Expected: codeforces)\n";
    cout << "Prefix count 'cod' after erase: " << trie.count_prefix("cod") << " (Expected: 2)\n";

    return 0;
}