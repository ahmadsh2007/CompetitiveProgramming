#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }
        sort(nums.begin(), nums.end());

        for (int i = 1; i < (int) nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};
// ! Copy ends here

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        Solution solver;
    
        int n; cin >> n;
        vector<int> nums(n);
        for (auto &x : nums) cin >> x;
    
        auto ans = solver.containsDuplicate(nums);
        // cout << "Result: [";
        cout << (ans ? "true" : "false") << endl;
        // cout << "]\n";
    }

    return 0;
}