#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    if (s.size() < 10) {
        std::cout << "NO";
        return 0;
    }

    for (char c : s) {
        if (c != 'a' && c != 'b') {
            std::cout << "NO";
            return 0;
        }
    }

    std::cout << "YES";
    return 0;
}
