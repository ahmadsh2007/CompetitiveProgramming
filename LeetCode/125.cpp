#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    bool isPalindrome(string & s) {
        int n = (int) s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (l < r and !isalnum(s[l])) l++;
            while (l < r and !isalnum(s[r])) r--;
            if (tolower(s[l++]) != tolower(s[r--])) return false; 
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
    
        auto ans = solver.isPalindrome(s);
        // cout << "Result: [";
        cout << (ans ? "true" : "false") << endl;
        // cout << "]\n";
    }

    return 0;
}