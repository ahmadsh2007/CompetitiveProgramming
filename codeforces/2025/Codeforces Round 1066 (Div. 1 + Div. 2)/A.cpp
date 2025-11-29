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
    vector<int> freq(n + 1, 0);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }
    
    int ans = freq[0];
    for(int i = 1; i <= n; i++){
        if (freq[i] == 0) continue;
        if (freq[i] == i) continue;
        
        if (freq[i] < i) ans += freq[i];
        else if (freq[i] > i) ans += freq[i] - i;
    }

    cout << ans << '\n';
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