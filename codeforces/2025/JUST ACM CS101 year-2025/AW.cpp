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

        long long profit = 0;
        long long max_future = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > max_future)
                max_future = a[i];
            else
                profit += (max_future - a[i]);
        }

        std::cout << profit << "\n";
    }

    return 0;
}