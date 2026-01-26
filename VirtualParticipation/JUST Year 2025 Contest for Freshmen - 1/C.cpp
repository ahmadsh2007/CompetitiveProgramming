#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int main() {
    int n; cin >> n;
    vector<int> freq(10001);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    int ans = 0;
    for (int i = 1; i <= 10001; i++) {
        ans = max(ans, freq[i] * i);
    }

    cout << ans << endl;
    return 0;
}