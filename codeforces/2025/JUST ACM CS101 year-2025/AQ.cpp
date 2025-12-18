#include <iostream>
#include <vector>
#include <cmath>

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long double> base(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        std::cin >> x;
        base[i] = log2((long double)x);
    }

    long long moves = 0;
    long double prev = base[0];
    const long double eps = 1e-12;

    for (int i = 1; i < n; ++i) {
        if (base[i] > prev + eps) {
            prev = base[i];
            continue;
        }

        long double diff = prev - base[i];
        long long c = (long long)floor(diff + eps) + 1;
        moves += c;
        base[i] += c;
        prev = base[i];
    }

    std::cout << moves << '\n';
    return 0;
}
