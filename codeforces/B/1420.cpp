#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int highestBit(int x) {
    int b = 0;

    // we count the highest bit
    while ((1 << (b + 1)) <= x) b++;
    return b;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    unordered_map<long long, long long> countByHighestBIT;

    for (auto x : a) {
        countByHighestBIT[highestBit(x)]++;
    }

    long long ans = 0;
    for (auto &x : countByHighestBIT) {
        long long c = x.second;
        ans += c * (c - 1) / 2;
    }

    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}