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

void solve() {
        long long n;
        cin >> n;

        long long ans = 0;
        map<long long, long long> freq;
        for (long long i = 1; i <= n; i++) {
            long long x; cin >> x;
            long long key = x - i;

            ans += freq[key];
            freq[key]++;
        }

        cout << ans << "\n";
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