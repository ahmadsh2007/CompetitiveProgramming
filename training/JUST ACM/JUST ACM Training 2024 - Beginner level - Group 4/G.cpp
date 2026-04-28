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

    vector<int> freq(5 + 1);
    for (int i = 0; i < n; i++) { 
        int x; cin >> x;
        freq[x]++;
    }

    int sum = freq[4];

    sum += freq[3];
    freq[1] = max(0, freq[1] - freq[3]);

    sum += freq[2] / 2;
    freq[2]  %= 2;

    if (freq[2] == 1) {
        sum++;
        // I didn't notice lol
        freq[1] = max(0, freq[1] - 2);
    }

    if (freq[1] > 0) {
        sum += ceil(freq[1] / 4.0);
    }

    cout << sum;
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