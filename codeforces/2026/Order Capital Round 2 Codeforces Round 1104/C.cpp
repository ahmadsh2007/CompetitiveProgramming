#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
void bubble(vector<int>&a) {
    int n = (int) a.size();
    for (int i = 0; i < n - 1; ++i) {
        bool change = 0;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int x = a[j];
                int y = a[j + 1];
                a[j] = y;
                a[j + 1] = x + y;
                change = 1;
            }
        }
        if (!change) break;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back(x);
            while ((int) a.size() >= 2 && a[(int) a.size() - 2] > a[(int) a.size() - 1]) {
                int x = a.back(); a.pop_back();
                int y = a.back(); a.pop_back();
                a.push_back(y);
                a.push_back(x + y);
            }
        }
        cout << a[(int) a.size() - 1] << endl;
    }
}