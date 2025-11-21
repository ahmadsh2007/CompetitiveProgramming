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
    int n, m; cin >> n >> m;

    int mn = 101, mx = -1;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
    }

    int mn1= 101;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] < mn1) mn1 = b[i];
    }

    int v = max(mx, mn * 2);
    if(v < mn1) cout << v;
    else cout << -1;


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
