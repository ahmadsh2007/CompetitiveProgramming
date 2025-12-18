#include <iostream>
using namespace std;

int main() {
    int h, n;
    cin >> h >> n;

    int result = ((h - n - 1) % 12 + 12) % 12 + 1; 
    cout << result << endl;

    return 0;
}