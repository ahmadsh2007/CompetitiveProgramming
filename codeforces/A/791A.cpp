#include <iostream>
// #include <cmath>

int main(){
    int a, b;
    std::cin >> a >> b;

    // a * 3 ^ x > b * 2 ^ x
    // double t = (logl(b) - logl(a)) / (logl(3.0L) - logl(2.0L));
    // int years_math = (long long)floorl(t) + 1;

    int years_while = 0;
    while (a <= b){
        a *= 3;
        b *= 2;
        years_while++;
    }

    // std::cout << years_math << '\n';
    std::cout << years_while;

    return 0;
}