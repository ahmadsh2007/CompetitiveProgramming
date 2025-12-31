#include <iostream>
#include <string>

int main() {
    std::string n; std::cin >> n;

    int len = n.size();
    int shorter = (1 << len) - 2;

    int value = 0;
    for (char c : n) {
        // value << 1 is as same as value * 2, so I just wrote it in this way for aura farming
        value = (value << 1) + (c == '7');
    }

    std::cout << shorter + value + 1 << '\n';
    return 0;
}