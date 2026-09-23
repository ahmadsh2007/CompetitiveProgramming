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

#define vi   vector<int>
#define vill vector<ll>

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

void solve() {
    str s; cin >> s;
    int n = (int) s.size();

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        bool have = 1;
        int l = i, r = i;
        while (l >= 0 and r < n) {
            if (s[l] == s[r]) {
                ans++;
            }
            else if (have) {
                ans++;
                have = 0;
            }
            else break;

            l--, r++;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        int cur = 0;
        bool have = 1;
        int l = i, r = i + 1;
        while (l >= 0 and r < n) {
            if (s[l] == s[r]) {
                ans++;
            }
            else if (have) {
                ans++;
                have = 0;
            }
            else break;

            l--, r++;
        }
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}