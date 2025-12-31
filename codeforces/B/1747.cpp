#include <iostream>
#include <stdio.h>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        // I don't know I keep getting 2 3 instead of 1 2
        if (n == 1) {
            std::cout << 1 << "\n1 2\n";
            continue;
        }

        int m = std::ceil(n/2.0); // C'mon, Python > Cpp
        std::cout << m << "\n";
        for (int k = 1; k <= m; k++) {
            int posA = 3 * k - 1; 
            int posN = 3 * (n - k + 1); // I know what went through your mind when you read N ╰(*°▽°*)╯
            printf("%d %d\n", posA, posN);
        }
    }

    return 0;
}