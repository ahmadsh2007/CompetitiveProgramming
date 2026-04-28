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
    string s; cin >> s;
    bool freq[n];

    int firstA = -1, lastB = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A' && firstA == -1) firstA = i;
        if (s[i] == 'B') lastB = i;
    }

    if (firstA == -1 || lastB == -1 || firstA > lastB) cout << 0 << '\n';
    else cout << (lastB - firstA) << '\n';
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