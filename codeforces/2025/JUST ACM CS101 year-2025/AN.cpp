#include <iostream>
#include <algorithm>

int main() {
    int x;
    int bestS = -1;

    while (std::cin >> x) {
        if (x == -1) break;
        int s = (37 * x) % 100;
        bestS = std::max(bestS, s);
    }

    std::cout << bestS << '\n';
    return 0;
}
