#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = (int) nums.size();
        unordered_set<int> freq;
        for (int i = 0; i < n; ++i) {
            freq.insert(nums[i]);
        }
        int maxLen = 0;
        for (auto &key : freq) {
            if (freq.find(key - 1) == freq.end()) {
                int curNum = key;
                int curLen = 1;

                while (freq.find(curNum + 1) != freq.end()) {
                    curNum++;
                    curLen++;
                }

                maxLen = max(maxLen, curLen);
            }
        }
        return maxLen;
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
    
        auto ans = solver.longestConsecutive(nums);
        // cout << "Result: [";
        cout << ans << endl;
        // cout << "]\n";
    }

    return 0;
}