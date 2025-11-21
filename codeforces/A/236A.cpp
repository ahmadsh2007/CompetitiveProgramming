#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') count1++;
        else if (s[i] == '2') count2++;
        else if (s[i] == '3') count3++;
    }

    bool first = true;
    for (int i = 0; i < count1; ++i) {
        if (!first) std::cout << '+';
        std::cout << '1';
        first = false;
    }
    for (int i = 0; i < count2; ++i) {
        if (!first) std::cout << '+';
        std::cout << '2';
        first = false;
    }
    for (int i = 0; i < count3; ++i) {
        if (!first) std::cout << '+';
        std::cout << '3';
        first = false;
    }

    return 0;
}