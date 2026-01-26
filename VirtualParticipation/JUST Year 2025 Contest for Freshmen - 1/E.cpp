#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
int main() {
    int x, y, z; cin >> x >> y >> z;
    for (int i = 0; i < z; i++) {
        char c; cin >> c;
        if (c == 'I') y--;
        x--;
    }

    cout << fixed << setprecision(2) << (float) y / x * 100 << endl;
}