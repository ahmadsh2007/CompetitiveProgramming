#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;
    int c = 0;
    
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        std::cin >> x;
        std::cin >> y;
        std::cin >> z;
        if (x + y + z >= 2) c+=1;
    }
    
    std::cout << c;
    return 0;
}