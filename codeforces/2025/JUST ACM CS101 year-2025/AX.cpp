#include <iostream>
#include <vector>

int main(){
    int n; std::cin >> n;

    std::vector<long long> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
        total += a[i];
    }

    long long pref = 0;
    int ans = -1;
    for (int i = 0; i < n; i++){
        pref += a[i];
        if (pref * 2 == total){
            ans = i + 1;
            break;
        }
    }

    std::cout << ans << '\n';
}