#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    int initialV = 0;
    
    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;
        if (operation == "X++" || operation == "++X") initialV += 1;
        if (operation == "X--" || operation == "--X") initialV -= 1;
    }
    
    std::cout << initialV;
    return 0;
}