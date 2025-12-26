#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[3] = {3 , 5 , 1};
    sort(a, a + 3);
    for (auto x : a) cout << x << ' ';
    cout << endl;
    sort(a, a + 3, greater<int>());
    for (auto x : a) cout << x << ' ';
    cout << endl;
}