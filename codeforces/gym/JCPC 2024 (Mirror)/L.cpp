#include <bits/stdc++.h>
using namespace std;
#define int long long
int N = 1e6 + 10;
vector<bool> primes(N, true);
vector<int> primesList;
static const int sieve = []() {
    primes[0] = primes[1] = false;
    primes[2] = true;
    primesList.push_back(2);
    for (int i = 2; i < N; ++i) {
        if (primes[i]) {
            primesList.push_back(i);
            for (int j = i * i; j < N; j += i) {
                primes[j] = false;
            }
        }
    }
    return 0;
}();
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = 0;
    for (const int & x : a) {
        if (primes[x]) continue;
        if (x % 2) {
            if (primes[x - 2]) {
                ans++;
            }
            else {
                ans += 2;
            }
        }
        else ans++;
    }

    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}