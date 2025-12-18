#include <iostream>
#include <iomanip>

int main() {
    double T, S1, D1, S2, D2;
    std::cin >> T >> S1 >> D1 >> S2 >> D2;
    double hamza_time = T + (D1 / S1);
    double noor_time = D2 / S2;

    if (abs(hamza_time - noor_time) < 1e-9)
        std::cout << "DRAW";
    else if (hamza_time < noor_time)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
