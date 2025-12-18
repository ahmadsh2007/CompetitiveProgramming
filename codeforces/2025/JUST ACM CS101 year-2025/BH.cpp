#include <iostream>
#include <string>

int main() {
    int q; std::cin >> q;

    while (q--) {
        std::string s, t; std::cin >> s >> t;

        int n = s.size(), m = t.size();
        int p = 0;

        while (p < n && p < m && s[p] == t[p]) p++;

        int ans = (p == 0) ? (n + m) : (n + m - p + 1); // better than if statement, don't think so?
        std::cout << ans << '\n';
    }
}
