#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int  n = (int) nums.size();
        map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> answer;
        for (auto &[key, cnt] : freq) {
            answer.push({cnt, key});
            if (answer.size() > k) answer.pop();
        }
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(answer.top().second);
            answer.pop();
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
        for (auto & x : nums) cin >> x;
        int k; cin >> k;
    
        auto ans = solver.topKFrequent(nums, k);
        cout << "[";
        for (int i = 0; i < k; ++i) cout << ans[i] << ",]"[i == k - 1];
        cout << endl;
    }

    return 0;
}