/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// Vector input/output operators
// I wish I could just do `v = list(map(int, input().split()))` instead of this boilerplate
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto& x:v) in>>x;
    return in;
}
// I wish I could just do `print(*v)` instead of this boilerplate
template<class T>
ostream& operator<<(ostream& out, vector<T>& v){
    for(auto& x:v) out<<x<<' ';
    return out;
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    // I just don't understand how A is harder than B and C, C is so easy then we jump to D which is mega hard?
    int s, q; cin >> s >> q;

    vector<int> divisors;
    for (int d = 1; d * d <= s; ++d) {
        if (s % d == 0) {
            divisors.push_back(d);
            if (d * d != s) {
                divisors.push_back(s / d);
            }
        }
    }

    sort(all(divisors));

    int n = (int) divisors.size();
    vector<int> prefixArea(n);
    prefixArea[0] = s;
    for (int i = 1; i < n; ++i) {
        prefixArea[i] = prefixArea[i - 1] + (divisors[i] - divisors[i - 1]) * (s / divisors[i]);
    }

    while (q--) {
        int x, y; cin >> x >> y;
        
        int Y = upper_bound(all(divisors), s / y) - divisors.begin() - 1;
        
        if (x <= divisors[Y]) {
            cout << x * y << endl;
            continue;
        }
        
        int area = divisors[Y] * y;
        
        int X = upper_bound(all(divisors), x) - divisors.begin() - 1;
        if (X > Y) {
            area += prefixArea[X] - prefixArea[Y];
        }
        
        if (x > divisors[X]) {
            area += (x - divisors[X]) * (s / divisors[X + 1]);
        }
        
        cout << area << endl;
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}