#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long R0, X, D;
        int n;
        cin >> R0 >> X >> D >> n;
        string s;
        cin >> s;

        long long L = R0, U = R0;
        long long ans = 0;

        for (char c : s) {
            if (c == '1') {
                // div.1: always rated
                ans++;
                long long newL = max(0LL, L - D);
                long long newU = U + D;
                L = newL; U = newU;
            } else { // c == '2'
                if (L < X) {
                    // Can choose a pre-round rating < X -> rated
                    ans++;
                    long long preLow = L;
                    long long preHigh = min(U, X - 1);
                    long long newL = max(0LL, preLow - D);
                    long long newU = preHigh + D;
                    L = newL; U = newU;
                } else {
                    // Entire feasible interval >= X -> unrated
                    // L, U unchanged
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
