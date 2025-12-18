#include <iostream>
#include <vector>

int main(){
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) std::cin >> a[i];

        bool okOdd = true, okEven = true;
        for (int i = 0; i < n; i += 2){
            if (a[i] % 2 == 0) okEven = false;
            if (a[i] % 2 == 1) okOdd = false;
        }
        if (!okEven && !okOdd){
            std::cout << "NO\n";
            continue;
        }

        okOdd = true, okEven = true;
        for (int i = 1; i < n; i += 2){
            if (a[i] % 2 == 0) okEven = false;
            if (a[i] % 2 == 1) okOdd = false;
        }
        if (!okEven && !okOdd){
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";
    }

    return 0;

}