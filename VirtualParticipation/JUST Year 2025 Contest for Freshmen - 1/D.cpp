#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    string a, b; cin >> a >> b;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] == '#') { cout << "NO\n"; return 0; }
    }

    for (int i = 1; i < n; i++) {
        if (a[i - 1] == b[i] && a[i - 1] == '#') { cout << "NO\n"; return 0; }
        else if (a[i] == b[i - 1] && a[i] == '#') { cout << "NO\n"; return 0; }
    }

    cout << "YES\n";
    return 0;
}