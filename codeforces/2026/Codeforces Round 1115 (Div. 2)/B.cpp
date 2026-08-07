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

    int offZero[2] = {0, 0}, offOnes[2] = {0, 0};
    
    int ans = LLONG_MAX;
    for (int i = 0; i < 2; ++i) {
        char t = (i ? '1' : '0');
        for (int j = 0; j < n; ++j) {
            if (s[j] == t) {
                t = (t == '1' ? '0' : '1');
            }
            else {
                if (s[j] == '1') offOnes[i]++;
                else offZero[i]++;
            }
        }
        if (abs(offZero[i] - offOnes[i]) <= 1) {
            ans = min(ans, offZero[i] + offOnes[i]);
        }
        if (t == '1' and s[n - 1] == '0') offZero[i]++;
        if (t == '0' and s[n - 1] == '1') offOnes[i]++;
        if (abs(offZero[i] - offOnes[i]) <= 1) {
            ans = min(ans, offZero[i] + offOnes[i]);
        }
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}