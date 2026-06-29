#include <bits/stdc++.h>
using namespace std;

#include "XorTrieTemplate.h"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    XorTrie xorTrie(100005);

    auto print_header = [](string title) {
        cout << "\n========================================\n  " << title << "\n========================================\n";
    };

    print_header("XOR TRIE: Maximum XOR Query");
    vector<int> nums = {3, 10, 5, 25, 2};
    for (int n : nums) xorTrie.insert(n);

    int query = 8; 
    int result = xorTrie.get_max_xor(query);
    cout << "Max XOR with 8: " << result << " (Expected: 17, since 8 ^ 25 = 17)\n";

    print_header("XOR TRIE: Deletion Handling");
    xorTrie.erase(25); // Remove optimal match
    result = xorTrie.get_max_xor(query);
    cout << "Max XOR with 8 after erasing 25: " << result << " (Expected: 13, since 8 ^ 5 = 13)\n";

    return 0;
}