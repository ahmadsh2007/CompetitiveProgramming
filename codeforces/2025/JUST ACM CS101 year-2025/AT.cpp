#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, c, d;
        std::cin >> n >> c >> d;

        double x[1111];
        double sum = 0;

        for (int i = 0; i < n; i++) {
            std::cin >> x[i];
            sum += x[i];
        }

        bool applicable = (sum >= c && n >= d);

        std::cout << (applicable ? 1 : 0) << endl;

        double total = 0;

        if (applicable) {
            for (int i = 0; i < n; i++) {
                double Ki = (x[i] / sum) * 100;
                double discounted = x[i] - (x[i] * Ki / 100);
                if (discounted < 0) discounted = 0;
                std::cout << fixed << setprecision(2) << discounted;
                if (i < n - 1) std::cout << " ";
                total += discounted;
            }
            std::cout << endl;
        } else {
            for (int i = 0; i < n; i++) {
                std::cout << fixed << setprecision(2) << x[i];
                if (i < n - 1) std::cout << " ";
                total += x[i];
            }
            std::cout << endl;
        }

        if (total < 0) total = 0;

        std::cout << fixed << setprecision(2) << total << endl;
    }

    return 0;
}
