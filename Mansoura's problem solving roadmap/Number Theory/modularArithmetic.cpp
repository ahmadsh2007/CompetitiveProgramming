#include <bits/stdc++.h>

using namespace std;

#define ll long long

signed main(){
    // If it is not guaranteed that the number will be positive
    // Use: (a % n + n) % n

    // If it is guaranteed, use:
    // a % n

    // This is how to calculate the Remainder
    // Remainder = a - n * floor(a / n)

    // If a % n == 0, then a divisible by n
    // if a % n == b % n, then (a - b) % n = 0

    // (a % n) % n = a % n
    // (n ^ x) % n = 0 for any x >= 0

    // (-a) % n != a % n
    // (((-a) % n) + (a % n)) % n = 0

    // (a + b) % n = (a % n + b % n) % n
    // (a + b + c) % n?
    // let's say that d = a + b, then
    // (a + b + c) % n = (d + c) % n = (d % n + c % n) % n
    // (a + b + c) % n = ((a % n + b % n) % n + c % n) % n

    // Let's say we have `int ans = 0` and want to add x multiple times, and each time mod it with y to prevent overflow
    // What we can do is
    // ans = (ans + x) % y, but notice that ans + x may overflow, so
    // we use this: ans = (ans % y + x % y) % y
    // We can also do: ```
    // ans += x % y
    // ans %= y
    // ```

    // (a - b) % n = (a % n - b % n + n) % n
    // (a * b) % n = (a % n * b % n) % n
}