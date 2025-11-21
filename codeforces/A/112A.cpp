#include <iostream>
#include <cctype>

int main(){
    std::string first, second;
    std::cin >> first >> second;
    for (int i = 0; i < first.size(); i++){
        char a = std::tolower(first[i]);
        char b = std::to5lower(second[i]);
        if (a < b) return std::cout << -1, 0;
        if (a > b) return std::cout << 1, 0;
    }
    std::cout << 0;
}