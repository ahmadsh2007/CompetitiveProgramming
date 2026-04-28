/*
Algorithm: Sieve of Eratosthenes

Idea:
- Precompute primality for all numbers from 1 to N
- Initially assume all numbers are prime
- For each prime i, mark all multiples of i as non-prime

Usage:
- Allows O(1) primality checks after preprocessing
- Useful when answering many prime queries up to N

Time Complexity:
- Preprocessing: O(N log log N)
- Each query: O(1)

Space Complexity:
- O(N)

One of the oldest and most fundamental algorithms in number theory,
commonly used in competitive programming.
*/

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
            for (int j = i * i; j <= N; j += i) {
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