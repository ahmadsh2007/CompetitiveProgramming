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
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;

    if (n == 2) {
        return void(cout << "! 1 2 1" << endl);
    }
    auto query = [](int u, int v, int d) -> int {
        cout << "? " << u << " " << v << " " << d << endl;
        int res; cin >> res;
        return res;
    };

    int u = 1;
    int mx = 0;
    for (int i = 2; i <= n; ++i) {
        while (query(1, i, mx + 1)) {
            mx++;
            u = i;
        }
    }

    int v = 1;
    int diameter = mx;
    for (int i = 1; i <= n; ++i) {
        if (i == u) continue;
        while (query(u, i, diameter + 1)) {
            diameter++;
            v = i;
        }
    }

    cout << "! " << u << " " << v << " " << diameter << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}