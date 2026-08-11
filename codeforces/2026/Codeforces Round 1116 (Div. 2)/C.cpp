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
    int n, k; cin >> n >> k;
    str s; cin >> s;

    int red = 0;
    int blu = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2) {
            if (s[i] == '1') {
                red++;
            }
        }
        else {
            if (s[i] == '1') {
                blu++;
            }
        }
    }

    for (int i = 0; i < 2 * n; ++i) {
        if (s[i] == '1' and s[(i + 1) % (2 * n)] == '0') {
            if (i % 2) {
                blu++;
                red--;
            }
            else {
                red++;
                blu--;
            }
        }
    }

    cout << red << ' ' << blu << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}