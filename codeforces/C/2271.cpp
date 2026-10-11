/*
      In the name of Allah, the Most Merciful
   I ask You, O Allah, for guidance and success
*/
#include <bits/stdc++.h>
using namespace std;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void spilt_mid(vector<int> & ans, int bit_pos, int l, int r) {
    if (l == r) return;
    
    int mid = (l + r) / 2;
    ans[mid] = (1ll << bit_pos);

    spilt_mid(ans, bit_pos + 1, l, mid - 1);
    spilt_mid(ans, bit_pos + 1, mid + 1, r);
}
void solve() {
    int n; cin >> n;
    int max_bit = 0;
    while ((1ll << (max_bit + 1)) <= n) {
        max_bit++;
    }
    int length = (1ll << (max_bit + 2)) - 1;

    vector<int> ans(length, 0);
    spilt_mid(ans, 0, 0, length - 1);

    cout << length << endl;
    for (auto &x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    cin >> TTT;
    while (TTT--) solve();
    return 0;
}