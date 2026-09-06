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

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

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
    vector<int> a(n);
    vector<int> c;
    int ones = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) {
            ones++;
        }
        else {
            c.push_back(ones);
            cur += ones;
        }
    }
    str s; cin >> s;

    int l = 0, r = (int) c.size() - 1, d = 0;
    cout << cur << ' ';
    for (int i = 0; i < n; ++i) {
        if (l <= r and d < ones) {
            if (s[i] == '0') {
                cur -= c[r] - d;
                r--;
            }
            else {
                while (l <= r and c[l] <= d) {
                    l++;
                }
                cur -= r - l + 1;
                d++;
            }
        }
        cout << cur << " \n"[i == n - 1];
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