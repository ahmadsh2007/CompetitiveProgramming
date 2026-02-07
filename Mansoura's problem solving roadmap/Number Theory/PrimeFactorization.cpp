#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printVector(const vector<ll> & a) {
    ll n = a.size();
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main() {
    ll n; cin >> n;

    // Prime factorization (inefficient approach)
    //
    // Idea:
    // We try every integer i starting from 2 up to n
    // If i divides n, it must be a prime factor (or divisible by a prime factor),
    // so we record it and divide n by i
    // We repeat until n becomes 1
    //
    // Correctness:
    // Every composite number has at least one divisor ≥ 2.
    // By always dividing n by the smallest possible divisor,
    // we ensure all prime factors are found
    //
    // Time Complexity:
    // Worst case O(n^2), extremely slow for large n
    auto primeFactorization = [](ll n) -> vector<ll> {
        vector<ll> primes;
        while (n != 1) for (ll i = 2; i <= n; i++) if (n % i == 0) {
            primes.push_back(i);
            n /= i;
            break;
        }

        return primes;
    };

    vector<ll> factorized = primeFactorization(n);
    printVector(factorized);


    // Prime factorization (efficient √n approach)
    //
    // Key Observation (Proof):
    // If n is a composite number, then it can be written as:
    //     n = a * b
    // where at least one of a or b satisfies:
    //     min(a, b) ≤ √n
    //
    // Proof:
    // Assume both a > √n and b > √n
    // => a * b > √n * √n = n  (contradiction)
    //
    // Therefore, if n has a divisor, one of them must be ≤ √n
    //
    // Algorithm:
    // 1. Try dividing n by all i from 2 to √n
    // 2. If i divides n, record i and divide n by i
    // 3. Repeat until n becomes 1
    // 4. If no divisor is found, n itself is prime
    //
    // Time Complexity:
    // O(√n)
    auto primeFactorizationBetterApproach = [](ll n) -> vector<ll> {
        vector<ll> primes;
        for (ll i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                primes.push_back(i);
                n /= i;
            }
        }
        if (n > 1) primes.push_back(n);
        return primes;
    };

    factorized.clear();
    factorized = primeFactorizationBetterApproach(n);
    printVector(factorized);
}