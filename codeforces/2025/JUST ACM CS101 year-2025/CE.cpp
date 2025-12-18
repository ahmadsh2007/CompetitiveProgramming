#include <iostream>
#include <vector>

int main(){
    int n; std::cin >> n;

    std::vector<long long> color(n + 1);
    int current = 0;

    for (int i = 2; i <= n; i++){
        // if we find a prime we give it a new color (i think this is the solution)
        if(color[i] == 0){
            current++;
            for (int j = i; j <= n; j += i) if (color[j] == 0) color[j] = current;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (i == n) std::cout << color[i] << '\n';
        else std::cout << color[i] << ' ';
    }
}