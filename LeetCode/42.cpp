#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int l = 0;
        int r = height.size() - 1;
        
        int mxL = 0;
        int mxR = 0;
        int ans = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= mxL) {
                    mxL = height[l];
                } else {
                    ans += mxL - height[l];
                }
                l++;
            } 
            else {
                if (height[r] >= mxR) {
                    mxR = height[r];
                } else {
                    ans += mxR - height[r];
                }
                r--;
            }
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