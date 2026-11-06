/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    string s; cin >> s;
    int n = (int) s.size();
    vector<int> freq(26);
    vector<vector<int>> cnt(26, vector<int>(26));
    for (const char& c : s) {
        for (int i = 0; i < 26; ++i) {
            cnt[i][c - 'a'] += freq[i];
        }
        freq[c - 'a']++;
    }

    int ans = *max_element(freq.begin(), freq.end());
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            ans = max(ans, cnt[i][j]);
        }
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}