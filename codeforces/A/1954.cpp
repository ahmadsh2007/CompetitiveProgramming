#include <iostream>
#include <cmath>

int main(){
    int t; std::cin >> t;

    while(t--){
        int n, m, k; std::cin >> n >> m >> k;

        if (n == 1 || m == 1){
            std::cout << "NO" << '\n';
            continue;
        }

        int ratio = std::ceil((float)n/m);
        int remaining = n - ratio;

        if (k < remaining) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}