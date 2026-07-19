#include <bits/stdc++.h>
using namespace std;


// ! Copy from here
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = (int) strs.size();
        vector<pair<string, int>> sorted(n);
        for (int i = 0; i < n; ++i) {
            sorted[i] = {strs[i], i};
            sort(sorted[i].first.begin(), sorted[i].first.end());
        }
        sort(sorted.begin(), sorted.end());

        vector<vector<string>> ret;
        int i = 0, j = 0;
        while (i < n) {
            j = i;
            vector<string> group;
            while (j < n and sorted[i].first == sorted[j].first) {
                group.push_back(move(strs[sorted[j].second]));
                j++;
            }
            ret.push_back(move(group));
            i = j;
        }
        return ret;
    }
};
// ! Copy ends here

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution solver;
    
        int n; cin >> n;
        vector<string> strs(n);
        for (auto & str : strs) cin >> str;
    
        auto ans = solver.groupAnagrams(strs);
        cout << "[";
        for (int v = 0; v < (int) ans.size(); ++v) {
            cout << "[";
            for (int i = 0; i < (int) ans[v].size(); ++i) {
                cout << "\"" << ans[v][i] << "\"" << ",]"[i == (int) ans[v].size() - 1];
            }
            cout << (v == (int) ans.size() - 1 ? "" : ",");
        }
        cout << "]\n";
    }

    return 0;
}