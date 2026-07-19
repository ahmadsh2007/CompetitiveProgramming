#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int st = 0;
        int en = (int) numbers.size() - 1;

        while (st < en) {
            int sum = numbers[st] + numbers[en];

            if (sum == target) return {st + 1, en + 1};
            if (sum < target) st++;
            else en--;
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
        vector<int> numbers(n);
        for (auto &x : numbers) cin >> x;
        int target; cin >> target;
    
        auto ans = solver.twoSum(numbers, target);
        cout << "Result: [";
        cout << ans[0] << ", " << ans[1];
        cout << "]\n";
    }

    return 0;
}