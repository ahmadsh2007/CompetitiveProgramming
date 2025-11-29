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
    long long y, k, n; cin >> y >> k >> n;

    long long start = y / k + 1;
    long long end = n / k;
    
    if (start > end) {
        cout << -1;
        return;
    }
    
    for (long long i = start; i <= end; ++i) {
        cout << (k * i - y) << " ";
    }
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
