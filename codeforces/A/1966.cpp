#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

int main(){
    int t; std::cin >> t;
    
    while(t--){
        int n, k; std::cin >> n >> k;

        std::vector<int> c(n);
        for (int i = 0; i < n; i++) std::cin >> c[i];

        std::unordered_map<int, int> freq;
        for(int x: c) freq[x]++;

        int maxF = 0;
        for (auto p : freq) maxF = std::max(maxF, p.second);

        if (maxF < k) std::cout << n << '\n';
        else std::cout << k - 1 << '\n';
    }
}