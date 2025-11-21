#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        int length = word.size();
        
        if (length > 10) {
            std::cout << word[0] << (length - 2) << word[length - 1] << '\n';
        } else {
            std::cout << word << '\n';
        }
    }
    
    return 0;
}