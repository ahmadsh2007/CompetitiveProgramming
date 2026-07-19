#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int) height.size();
        if (n == 0) return 0;

        vector<int> prefix(n), suffix(n);

        prefix[0] = height[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = max(prefix[i - 1], height[i]);
        }

        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix[i] = max(suffix[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(prefix[i], suffix[i]) - height[i];
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
        vector<int> height(n);
        for (auto &x : height) cin >> x;
    
        auto ans = solver.trap(height);
        // cout << "Result: [";
        cout << ans << endl;
        // cout << "]\n";
    }

    return 0;
}