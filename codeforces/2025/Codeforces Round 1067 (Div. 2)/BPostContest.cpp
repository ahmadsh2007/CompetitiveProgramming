#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define str string // What a Python

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;

    map<int, int> freq;
    for (int i = 0; i < 2 * n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    int oddCounter = 0;
    int eveCounter = 0;

    for (auto &[val, cnt] : freq){
        if (cnt % 2 == 1) oddCounter++;
        else eveCounter++;
    }

    int ans;
    if(oddCounter > 0) ans = oddCounter + 2 * eveCounter;
    else if (n % 2 == 0) ans = 2 * eveCounter;
    else {
        if (eveCounter == 1) ans = 2;
        else ans = 2 * eveCounter - 2;
    }

    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}