#include <iostream>
#include <vector>
#include <cmath>

int main(){
    long long n, l, r, x; std::cin >> n >> l >> r >> x;

    std::vector<long long> c(n);
    for (int i = 0; i < n; i++) std::cin >> c[i];

    int answer = 0;
    for (int i = 0; i < (1 << n); i++) {
        long long sum = 0, minimum = 1000000000, maximum = -1;
        int F1 = 0;

        for (int j = 0; j < n; j++) {
            int bit = (i / (int)pow(2, j)) % 2;
            if (bit == 1) {
                sum += c[j];
                minimum = std::min(minimum, c[j]);
                maximum = std::max(maximum, c[j]);
                F1++;
            }
        }

        if (F1 >= 2 && sum >= l && sum <= r && maximum - minimum >= x)
            answer++;
    }
    std::cout << answer;

}