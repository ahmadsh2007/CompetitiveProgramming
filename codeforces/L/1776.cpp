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
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    int q; cin >> q;

    int minusCnt = 0, plusCnt = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '+') plusCnt++; else minusCnt++;

    auto check = [](int mn, int mx, int a, int b, int mid) -> int {
        mn -= mid, mx -= mid;
        if (mn < 0 || mx < 0) return -1;

        int p = mn * b;
        int q = mx * a;

        if (p == q) return 0;
        if (p < q) return -1;
        if (q < p) return 1;
    };

    while (q--) {
        int a, b; cin >> a >> b;
        int g = gcd(a, b);
        a /= g, b /= g;

        int mn = (minusCnt < plusCnt ? minusCnt : plusCnt);
        int mx = (minusCnt > plusCnt ? minusCnt : plusCnt);

        b += a;
        a = min(a, b - a);
        b -= a;

        int l = 0, r = 1e18, mid;
        bool ans = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int c = check(mn, mx, a, b, mid);
            if (c == 0) {
                ans = 1;
                break;
            } else if (c == 1) {
                l = mid + 1;
            } else if (c == -1) {
                r = mid - 1;
            }

        }
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

const int TESTCASES = 0;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef LOCAL
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}