#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int) height.size();
        int area = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int len = r - l;
            area = max(area, len * min(height[l], height[r]));
            if (l < r and height[l] < height[r]) l++;
            else r--;
        }
        return area;
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
        int target; cin >> target;
    
        auto ans = solver.maxArea(height);
        // cout << "Result: [";
        cout << ans << endl;
        // cout << "]\n";
    }

    return 0;
}