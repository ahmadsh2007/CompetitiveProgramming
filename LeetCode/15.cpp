#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int k = n - 1;

            int target = -nums[i];
            while (j < k) {
                int total = nums[j] + nums[k];
                if (total > target) k--;
                else if (total < target) j++;
                else {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j - 1] and j < k) j++;
                }
            }
        }
        return ret;
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
    
        auto ans = solver.threeSum(nums);
        
        // TODO: output...
    }

    return 0;
}