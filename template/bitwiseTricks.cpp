#include <bits/stdc++.h>
using namespace std;

/**
 * BITWISE OPERATIONS TEMPLATE
 * Based on the blog by "Raha Ahmed's Support"[cite: 1]
 */

typedef long long ll;

// ============================================================================
// 1. BASIC CHECKS
// ============================================================================

/**
 * Checks if a number is even.
 * Numbers ending with 0 in binary are even[cite: 1].
 */
bool is_even(ll n) { return !(n & 1); }

/**
 * Checks if a number is odd.
 * Numbers ending with 1 in binary are odd[cite: 1].
 */
bool is_odd(ll n) { return (n & 1); }

/**
 * Checks if a number is a power of 2.
 * A power of 2 has only one set bit[cite: 1].
 */
bool is_power_of_two(ll n) { return n > 0 && (n & (n - 1)) == 0; }


// ============================================================================
// 2. K-TH BIT MANIPULATION (0-indexed)
// ============================================================================

/**
 * Checks if the k-th bit is Set (1) or Not Set (0)[cite: 1].
 */
bool get_bit(ll n, int k) { return (n >> k) & 1; }

/**
 * Turns the k-th bit ON (1) using OR[cite: 1].
 */
ll set_bit(ll n, int k) { return n | (1LL << k); }

/**
 * Turns the k-th bit OFF (0) using AND and NOT[cite: 1].
 */
ll clear_bit(ll n, int k) { return n & ~(1LL << k); }

/**
 * Flips the k-th bit (0->1 or 1->0) using XOR[cite: 1].
 */
ll toggle_bit(ll n, int k) { return n ^ (1LL << k); }


// ============================================================================
// 3. BUILT-IN OPTIMIZED FUNCTIONS (GCC)
// ============================================================================

/**
 * Returns the total number of set bits (1s)[cite: 1].
 */
int count_set_bits(ll n) { return __builtin_popcountll(n); }

/**
 * Returns the number of leading zeros (zeros before the first 1)[cite: 1].
 */
int lead_zeros(ll n) { return (n == 0 ? 64 : __builtin_clzll(n)); }

/**
 * Returns the number of trailing zeros (zeros after the last 1)[cite: 1].
 */
int trail_zeros(ll n) { return (n == 0 ? 64 : __builtin_ctzll(n)); }


// ============================================================================
// 4. LOWEST SET BIT (LSB) TRICKS
// ============================================================================

/**
 * Removes the rightmost 1-bit from the number[cite: 1].
 * Example: 12 (1100) -> 8 (1000)
 */
ll remove_lowest_bit(ll n) { return n & (n - 1); }

/**
 * Extracts the value of the rightmost 1-bit[cite: 1].
 * Example: 12 (1100) -> 4 (0100)
 */
ll get_lowest_bit_val(ll n) { return n & (-n); }


// ============================================================================
// 5. ADVANCED CP PATTERNS
// ============================================================================

/**
 * Finds the unique element in an array where every other element 
 * appears exactly twice[cite: 1].
 */
int find_unique(const vector<int>& a) {
    int xr = 0;
    for (int x : a) xr ^= x;
    return xr;
}

/**
 * Generates and prints all 2^N subsets of a vector using bitmasking[cite: 1].
 */
void generate_subsets(const vector<int>& a) {
    int n = a.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) cout << a[i] << " ";
        }
        cout << "}" << endl;
    }
}

// ============================================================================
// MAIN EXECUTION
// ============================================================================

void run_tests();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    run_tests();
    return 0;
}

void run_tests() {
    cout << "--- Starting Bitwise Logic Tests ---\n";

    // 1. Test Odd/Even [Trick 1]
    assert(is_odd(13) == true);   // 1101
    assert(is_even(10) == true);  // 1010
    cout << "Test 1 (Odd/Even): PASSED\n";

    // 2. Test K-th Bit Manipulation [Trick 2, 5, 6]
    ll n = 13; // 1101
    assert(get_bit(n, 2) == true);  // 2nd bit is 1
    assert(get_bit(n, 1) == false); // 1st bit is 0[cite: 1]
    
    n = set_bit(n, 1);    // 1101 -> 1111 (15)[cite: 1]
    assert(n == 15);
    
    n = clear_bit(n, 3);  // 1111 -> 0111 (7)[cite: 1]
    assert(n == 7);
    
    n = toggle_bit(7, 0); // 0111 -> 0110 (6)[cite: 1]
    assert(n == 6);
    cout << "Test 2 (K-th Bit): PASSED\n";

    // 3. Test Power of Two [Trick 12]
    assert(is_power_of_two(16) == true);  // 10000[cite: 1]
    assert(is_power_of_two(13) == false); // 1101[cite: 1]
    assert(is_power_of_two(0) == false);  // Boundary case[cite: 1]
    cout << "Test 3 (Power of 2): PASSED\n";

    // 4. Test LSB Tricks [Trick 8, 9]
    ll val = 12; // 1100
    assert(remove_lowest_bit(val) == 8);   // 1100 -> 1000[cite: 1]
    assert(get_lowest_bit_val(val) == 4);  // Rightmost 1 is at 2^2[cite: 1]
    cout << "Test 4 (LSB Logic): PASSED\n";

    // 5. Test Built-ins [Trick 4, 10]
    assert(count_set_bits(13) == 3);  // 1101 has three 1s[cite: 1]
    assert(trail_zeros(40) == 3);     // 101000 has three 0s at the end[cite: 1]
    cout << "Test 5 (Built-ins): PASSED\n";

    // 6. Test Unique Element [Trick 13]
    vector<int> v = {2, 3, 5, 3, 2};
    assert(find_unique(v) == 5);      // XOR cancels pairs[cite: 1]
    cout << "Test 6 (Unique Element): PASSED\n";

    cout << "--- All Logic Tests Passed! ---\n";
}