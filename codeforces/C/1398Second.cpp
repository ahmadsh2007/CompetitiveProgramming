#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
        map<long long, long long> count;
        count[0]++;
        // sum of a[i] from l to r ([l, r]) must be equal to (r - l + 1)
        // if we remove l, it becomes sum of (l, r] must be equal to (r - l)
        // reorder the equation, prefix[r] - r = prefix[l] - l
        // so we need to count the number of prefix[i] - i
        // then use combinatorics (n , 2) which is n * (n - 1) / 2
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i - 1];
            count[sum - i]++;
        }
        long long ans = 0;
        for (auto &[key, cnt] : count) ans += cnt * (cnt - 1) / 2;
        cout << ans << '\n';
    }
}