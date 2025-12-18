#include <iostream>
#include <string>

int main() {
    std::string theWord;
    getline(std::cin, theWord);
    char ch;
    std::cin >> ch;

    std::string result = "";
    for (int i = 0; i < (int)theWord.size(); ++i) {
        if (theWord[i] == '[') {
            int n = theWord[i + 1] - '0';
            result.append(n, ch);
            i += 2;
        } else {
            result += theWord[i];
        }
    }

    std::cout << result;
    return 0;
}
