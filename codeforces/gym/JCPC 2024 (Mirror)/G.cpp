#include <bits/stdc++.h>
using namespace std;
#define int long long
int N = 1e6 + 10;
vector<bool> primes(N, true);
vector<int> primesList;
vector<int> spf(N);
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
    // for (int i = 2; i < N; ++i) {
    //     if (!spf[i]) {
    //         for (int j = i; j < N; j += i) {
    //             spf[j] = i;
    //         }
    //     }
    // }
    return 0;
}();
void solve() {
    int n; cin >> n;
    int idx = upper_bound(primesList.begin(), primesList.end(), n) - primesList.begin() - 1;

    if (n < 3) {
        return void(cout << "-1\n");
    }
    else if (n == 3) {
        return void(cout << "1 1 1" << endl);
    }

    int target = primesList[idx];
    
    if (target % 2) {
        cout << 1 << ' ' << target / 2 << ' ' << target / 2 << endl;
    }
    else {
        cout << 2 << ' ' << target / 2 - 1 << ' ' << target / 2 - 1 << endl;
    }
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