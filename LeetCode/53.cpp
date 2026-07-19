#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        for (int i = 1; i < (int) nums.size(); ++i) {
            maxSum = max(maxSum, nums[i]);
        }
        int cur = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            cur += nums[i];

            maxSum = max(maxSum, cur);
            if (cur < 0) cur = 0;
        }
        return maxSum;
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
    
        auto ans = solver.maxSubArray(nums);
        // cout << "Result: [";
        cout << ans << endl;
        // cout << "]\n";
    }

    return 0;
}