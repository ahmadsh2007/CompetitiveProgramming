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
    int n; cin >> n;

    int ans = -1, current = 1;
    vector<int> a(n);
    cin >> a[0];
    for (int i = 1; i < n; i++){
        cin >> a[i];
        if (a[i] >= a[i - 1]) current++;
        else { ans = max(ans, current); current = 1; }
    }
    ans = max(ans, current);
    cout << ans;
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
