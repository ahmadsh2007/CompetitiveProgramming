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

    int onTable = 0;
    int mx = 0;
    set<int> s;
    for(int i = 0; i < n * 2; i++){
        int x; cin >> x;

        if (s.find(x) != s.end()) onTable--;
        else onTable++;

        s.insert(x);

        mx = max(mx, onTable);
    }

    cout << mx;
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