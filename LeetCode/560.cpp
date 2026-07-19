#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int) nums.size();

        int prefix[n];
        prefix[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<int, int> mp;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (prefix[i] == k) ans++;

            if (mp.find(prefix[i] - k) != mp.end()) {
                ans += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }

        return ans;
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
        int k; cin >> k;
    
        auto ans = solver.subarraySum(nums, k);
        // cout << "Result: [";
        cout << ans << endl;
        // cout << "]\n";
    }

    return 0;
}