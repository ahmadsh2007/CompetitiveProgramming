#include <iostream>
#include <vector>

int main(){
    int n; std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    int m; std::cin >> m;

    std::vector<long long> s(m);
    for (int i = 0; i < m; i++) std::cin >> s[i];

    int position = 0;
    for (int i = 0; i < m; i++){
        position += s[i];
        std::cout << a[position] << " ";
    }
}