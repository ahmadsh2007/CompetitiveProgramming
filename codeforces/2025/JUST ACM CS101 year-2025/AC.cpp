#include <iostream>
using namespace std;

int main() {
    long long w, x, y, z;
    cin >> w >> x >> y >> z;

    long long B = (w - y + x - z) / 2;
    long long A = w - B;
    long long C = x - B;
    long long D = A - z;

    cout << A << " " << B << " " << C << " " << D << endl;
    return 0;
}