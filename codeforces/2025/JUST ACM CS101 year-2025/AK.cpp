#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;

    if ((x - 12) % 8 != 0) {
        cout << "-_-";
        return 0;
    }

    long long n = (x - 12) / 4;
    cout << n << " " << n + 2 << " " << n + 4 << " " << n + 6;
    return 0;
}
