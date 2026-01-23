#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int a, b, c; cin >> a >> b >> c;
    int x = (a * b) - c;
    int y = (a * c) - b;
    int z = (b * c) - a;

    cout << min({x, y, z});
}