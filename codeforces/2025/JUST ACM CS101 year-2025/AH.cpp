#include <iostream>

int main(){
    int n, k, c; std::cin >> n >> k >> c;

    int cost = n * k - c;
    if(cost <= 0) std::cout << "FREE";
    else std::cout << cost;
}