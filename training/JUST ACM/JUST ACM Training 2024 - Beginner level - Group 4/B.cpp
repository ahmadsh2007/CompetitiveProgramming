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
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++){
        freq[tolower(s[i]) - 'a']++;
        // cout << s[i] << '\n';
        // cout << tolower(s[i]) << '\n';
    }

    for(int i = 0; i < 26; i++) if (freq[i] < 1) { cout << "NO\n"; return; }
    cout << "YES\n";
}
 

int main() {
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //   freopen("output.txt", "w", stdout);
    // #endif

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}