#include <iostream>
#include <algorithm>

int main(){
    int n; std::cin >> n;

    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int min_x = std::min({x1, x2, x3, x4});
    int max_x = std::max({x1, x2, x3, x4});
    int min_y = std::min({y1, y2, y3, y4});
    int max_y = std::max({y1, y2, y3, y4});
        
    while(n--){
        int x, y; std::cin >> x >> y;

        if (x > min_x && x < max_x && y > min_y && y < max_y) std::cout << "Inside\n";
        else if ((x >= min_x && x <= max_x && (y == min_y || y == max_y)) ||
                 (y >= min_y && y <= max_y && (x == min_x || x == max_x)))
            std::cout << "On The Border\n";
        else std::cout << "Outside\n";
    }
}