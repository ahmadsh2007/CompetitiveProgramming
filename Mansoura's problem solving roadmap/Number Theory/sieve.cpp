#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printVector(const vector<ll> & a) {
    ll n = a.size();
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

const int N = 1000000;

void solve(const vector<bool> & isPrime) {
    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        cout << isPrime[x] << endl;
    }
}

vector<bool> sieve(int N) {
    vector<bool> isPrime(N + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    return isPrime;
}

signed main() {
    #ifndef ONLINE_JUDGE
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #endif
    vector<bool> isPrime = sieve(N);
    int TTT = 1;
    // cin >> TTT;
    while (TTT--) solve(isPrime);
    return 0;
}