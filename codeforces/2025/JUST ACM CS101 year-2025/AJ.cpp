#include <iostream>
#include <algorithm>

int main() {
    int A, B, C, D, E;
    std::cin >> A >> B >> C >> D >> E;
    int costA, costB;
    std::cin >> costA >> costB;

    int negatives = 0;
    if (A == -1) negatives++;
    if (B == -1) negatives++;
    if (C == -1) negatives++;
    if (D == -1) negatives++;
    if (E == -1) negatives++;

    if (negatives % 2 == 0) {
        std::cout << 0;
    } else {
        if (negatives == 5)
            std::cout << costA;
        else
            std::cout << std::min(costA, costB);
    }

    return 0;
}
