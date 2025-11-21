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

    int mxInd, mnInd, mx = -1, mn = 101;

    vector<int> a(n);
    for (auto &x: a) cin >> x;

    for(int i = 0; i < n; i++){
        if(a[i] <= mn) { mn = a[i]; mnInd = i; }
        if(a[i] > mx) { mx = a[i]; mxInd = i; }
    }
    if(mxInd > mnInd) cout << mxInd - 2 - mnInd + n;
    else cout << mxInd - 1 - mnInd + n;

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
