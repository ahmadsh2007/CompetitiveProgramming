#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int price;
        std::cin >> price;
        total += price;
    }

    std::cout << total;
    return 0;
}
