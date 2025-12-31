// desperate test
#include <iostream>
#include <cmath>
#include <stdio.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int X, Y, K;
        std::cin >> X >> Y >> K;
        int M = std::min(X, Y);

        printf("0 0 %d %d\n", M, M);
        printf("0 %d %d 0\n", M, M);
    }
}