// 171 ms!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// I have to make it faster

#include <iostream>
#include <vector>

// const to prevent editing (I think it can make it faster) and pointer to always point to the same array instead of making a copy of it
int maxPrefixSum(const std::vector<int> &arr){
    int sum = 0, best = 0;
    for (int x: arr){
        sum += x;
        if (sum > best) best = sum;
    }
    return best;
}

int main(){
    // IO optimization (The best optimization ever)
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int t; std::cin >> t;

    while(t--){
        int n; std::cin >> n;

        std::vector<int> r(n);
        for (int _ = 0; _ < n; _++) std::cin >> r[_];

        int m; std::cin >> m;

        std::vector<int> b(m);
        for (int _ = 0; _ < m; _++) std::cin >> b[_];

        int IDontKnowWhat2NameIt = maxPrefixSum(r) + maxPrefixSum(b);
        std::cout << IDontKnowWhat2NameIt << '\n';
    }
}