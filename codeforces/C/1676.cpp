#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cmath>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i)
            std::cin >> s[i];

        int ans = 2147483647;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int diff = 0;
                for (int k = 0; k < m; ++k)
                    diff += abs(s[i][k] - s[j][k]);
                ans = std::min(ans, diff);
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}