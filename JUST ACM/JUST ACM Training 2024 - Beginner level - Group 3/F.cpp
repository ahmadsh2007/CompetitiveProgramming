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

    // Let's flush it
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    set<string> s;
    for(int i = 0; i < n; i++){
        string ss; getline(cin, ss);
        s.insert(ss);
    }

    for(auto &x: s) cout << x << '\n';
    cout << s.size();
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