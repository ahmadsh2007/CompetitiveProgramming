#include <bits/stdc++.h>

using namespace std;

#define ll long long

void printVector(vector<ll> & a) {
    ll n = a.size();
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }

    return;
}

signed main() {
    ll n; cin >> n;
    
    // Naive approach is to check each number, Time Complexity: O(n)
    auto get_divisors = [&](ll n) {
        vector<ll> divisors;
        for (ll i = 1; i <= n; i++) {
            if (n % i == 0) divisors.push_back(i);
        }
        
        return divisors;
    };
    
    vector<ll> answer;
    answer = get_divisors(n);
    printVector(answer);

    // Let's explain the other approach
    // Let's say we have 12 and we want to find its divisors
    // From 1 to n (12): 1 2 3 4 5 6 7 8 9 10 11 12
    // We found that 1, 2, 3, 4, 6 and 12 are the divisors of 12
    // Can you see the pattern there? No? No problem
    // What we can see is that the very first (1) is connected to the very last (12) and so on
    // 1 * 12 = 2 * 6 = 3 * 4 = 12, so what now?
    // All we need is to find the first half to find the other half
    // Now all we need is an indicator to stop
    // x    *   y   =   n
    // 1    *   12  =   12
    // 2    *   6   =   12
    // 3    *   4   =   12
    // The indicator is two rules: 1. x is less or equal (<=) y, 2. x * y is less or equal (<=) n
    // Then y is less or equal (<=) n / x
    // We can merge two rules: 1. x <= y, 2. y <= n / x
    // Then x <= n / x, then x ^ 2 <= n
    // The Time Complexity of this approach is: O(sqrt(n))

    auto get_divisors_better_approach = [&](ll n) {
        vector<ll> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }

        return divisors;
    };

    vector<ll> answer_better_approach;
    answer_better_approach = get_divisors_better_approach(n);
    printVector(answer_better_approach);

}