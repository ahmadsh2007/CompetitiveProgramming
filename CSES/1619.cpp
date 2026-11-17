/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int n; cin >> n;
    vector<pair<int, int>> time;
    time.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        time.push_back({a, 1});
        time.push_back({b, -1});
    }

    sort(time.begin(), time.end());

    int ans = 0, cur = 0;
    for (auto &[key, val] : time) {
        cur += val;
        ans = max(ans, cur);
    }
    
    cout << ans << endl;
    return 0;
}