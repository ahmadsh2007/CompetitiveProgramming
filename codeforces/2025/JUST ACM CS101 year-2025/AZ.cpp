#include <iostream>
#include <string>

int main() {
    std::string s, q;
    int i, j;

    std::cin >> s;
    std::cin >> i >> j;
    std::cin >> q;

    i--; 
    j--;

    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;

    int index = -1;
    for (int k = 0; k <= (int)s.size() - (int)q.size(); k++) {
        if (s.substr(k, q.size()) == q) {
            index = k + 1;
            break;
        }
    }

    std::cout << index;

    return 0;
}
