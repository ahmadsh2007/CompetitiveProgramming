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
    // Solve one: Vectors
    long long N, M; cin >> N >> M;

    vector<int> w(N);
    for (auto &x : w) cin >> x;
    sort(w.begin(), w.end());

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if (M >= w[i]) {
            ans += 1;
            M += 1;
        } else {
            break;
        }
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
