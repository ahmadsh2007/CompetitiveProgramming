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
    int n, b; cin >> n >> b;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;

    vector<int> costs;
    int odd = 0, eve = 0;

    for (int i = 0; i < n - 1; i++){
        if(a[i] % 2 == 0) eve += 1;
        else odd += 1;

        if (odd == eve) {
            costs.push_back(abs(a[i] - a[i + 1]));
        }
    }

    sort(costs.begin(), costs.end());

    for (int c: costs){
        if (b >= c){
            b -= c;
            ans++;
        } else break;
    }

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
