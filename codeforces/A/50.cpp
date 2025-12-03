#include <iostream>
 
int main() {
    int N, M;
    std::cin >> N >> M;
    const int domSize = 2;
    std::cout << N * M / domSize;
}