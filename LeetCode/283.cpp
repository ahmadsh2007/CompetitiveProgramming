#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = (int) nums.size();
        int left = 0;
        for (int right = 0; right < n; ++right) {
            if (nums[right] != 0) {
                swap(nums[left++], nums[right]);
            }
        }
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
    
        solver.moveZeroes(nums);

        cout << "[";
        for (int i = 0; i < n; ++i) cout << nums[i] << ",]"[i == n - 1];
        cout << "\n";
    }

    return 0;
}