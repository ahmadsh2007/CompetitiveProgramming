#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Point {
    int x;
    int y;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        int S; cin >> S;
        
        double RG = sqrt(S);
        double EG = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));

        cout << fixed << setprecision(7) << (RG - EG) * (RG - EG) * .5 << endl;
    }

    return 0;
}