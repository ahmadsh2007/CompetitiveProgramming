#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    bool isAnagram(string s, string t) {
        if ((int) s.size() != (int) t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < (int) s.size(); ++i) {
            if (s[i] != t[i]) return false;
        }
        return true;
    }
};
// ! Copy ends here

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        Solution solver;
    
        string s; cin >> s;
        string t; cin >> t;
    
        auto ans = solver.isAnagram(s, t);
        // cout << "Result: [";
        cout << (ans ? "true" : "false") << endl;
        // cout << "]\n";
    }

    return 0;
}