#include <iostream>

int main(){
    long long n;
    std::cin >> n;
    int sum = n * (n + 1) / 2;
    int k = n / 3;
    int s3 = k * (k + 1) / 2;
    std::cout << sum - 3 * s3;
}