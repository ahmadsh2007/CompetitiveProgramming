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
    int n; cin >> n;
    str s; cin >> s;

    for (int i = 1; i < n - 1; ++i) {
        if (s[i - 1] == s[i + 1] and s[i - 1] != '?') {
            return void(cout << 0 << endl);
        }
    }

    int part[2] = {0, 0};
    for (int j = 0; j <= 1; ++j) {
        bool ok = 1;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != '?') {
                int k = (j + (i / 2)) % 2;
                if ((s[i] - '0') != k) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) part[0]++;
    }

    for (int j = 0; j <= 1; ++j) {
        bool ok = 1;
        for (int i = 1; i < n; i += 2) {
            if (s[i] != '?') {
                int k = (j + (i / 2)) % 2;
                if ((s[i] - '0') != k) {
                    ok = 0;
                    break;
                }
            }
        }
        if (ok) part[1]++;
    }

    cout << part[0] * part[1] << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}