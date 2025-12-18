#include <iostream>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        bool reached = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            k += x;
            if (k >= 1400) reached = true;
        }
        cout << (reached ? "YES" : "NO") << endl;
    }
}