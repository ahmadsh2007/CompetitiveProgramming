#include <iostream>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    int times[111];
    int drivers[111];

    for (int i = 0; i < N; i++) {
        std::cin >> times[i];
        drivers[i] = i + 1;
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (times[j] < times[i]) {
                int temp = times[i];
                times[i] = times[j];
                times[j] = temp;

                int tmpDriver = drivers[i];
                drivers[i] = drivers[j];
                drivers[j] = tmpDriver;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        std::cout << drivers[i];
        if (i < N - 1) std::cout << " ";
    }

    return 0;
}
