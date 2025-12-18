#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        sum += a;
    }

    double rate = static_cast<double>(sum) / n;
    cout << fixed << setprecision(3) << rate;

    return 0;
}