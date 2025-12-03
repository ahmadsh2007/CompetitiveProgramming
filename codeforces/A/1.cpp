#include <iostream>

int main(void){
    long long n, m, a;
    std::cin >> n >> m >> a;

    // you can use ceil() instead, but import cmath library first
    long long tiles_n = (n + a - 1) / a; // ceil(n / (float) a)
    long long tiles_m = (m + a - 1) / a; // ceil(m / (float) a)

    std::cout << tiles_n * tiles_m;
    return 0;
}
