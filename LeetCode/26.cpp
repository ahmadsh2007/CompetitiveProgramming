#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) return 0;

        int k = 1;
        int lastNumber = nums[0];
        int idx = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != lastNumber) {
                swap(nums[i], nums[idx++]);
                lastNumber = nums[idx - 1];
                k++;
            }
        }
        return k;
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
    
        int k = solver.removeDuplicates(nums);

        // No output
    }

    return 0;
}