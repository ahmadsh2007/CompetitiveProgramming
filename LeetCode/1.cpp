#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;

        for (int i = 0; i < (int) nums.size(); ++i) {
            int rem = target - nums[i];
            
            if (hashTable.find(rem) != hashTable.end()) {
                return {i, hashTable[rem]};
            }

            hashTable[nums[i]] = i;
        }   
        return {};
    }
};
// ! Copy ends here

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        Solution solver;
    
        int n; cin >> n;
        vector<int> num(n);
        for (auto &x : num) cin >> x;
        int target; cin >> target;
    
        auto ans = solver.twoSum(num, target);
        cout << "Result: [";
        cout << ans[0] << ", " << ans[1];
        cout << "]\n";
    }

    return 0;
}