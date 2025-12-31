#include <iostream>
#include <vector>

int main(){
    int t; std::cin >> t;

    while(t--){
        long long n; std::cin >> n;

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        bool symmetrical = (a[0] == n);
        int pointer = n; // I just don't know what to name it ngl
        for (int i =1; symmetrical && i <= n; i++){
            while(pointer > 0 && a[pointer - 1] < i) pointer -= 1;
            if(a[i - 1] != pointer) symmetrical = 0;
        }

        if (symmetrical) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}