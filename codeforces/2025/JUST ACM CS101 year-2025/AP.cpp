#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    int scores[100];
    int n = 0, x;

    while (std::cin >> x && x != -1)
        scores[n++] = x;

    std::sort(scores, scores + n);

    int sum = 0;
    for (int i = 2; i < n; i++)
        sum += scores[i];

    double avg = (double)sum / (n - 2);
    double result = avg * 20 / 100;

    std::cout << std::fixed << std::setprecision(6) << result << '\n';
    return 0;
}
