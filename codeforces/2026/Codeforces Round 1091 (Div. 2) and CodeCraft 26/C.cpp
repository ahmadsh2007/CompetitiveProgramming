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
    int n, m, a, b; cin >> n >> m >> a >> b;

    bool ok = 1;
    int g1 = gcd(n, a);
    int g2 = gcd(m, b);
    if ((g1 != 1 || g2 != 1)) ok = 0;

    bool DEBUG = 0;
    if (DEBUG) {
        if (m == 4134) {
            int val = 0;
            int rot = 0;
            for (int i = 0; i < 30; ++i) {
                val += m;
                val %= b;
                rot++;
                if (val == 0) break;
            }
            cout << "rot: " << rot << endl;
        }
        cout << "val: " << g1 << ' ' << g2 << endl;
        cout << "res: " << (ok ? "YES\n" : "NO\n");
        cout << endl;
        return;
    }
    
    if (!ok) {cout << "NO\n"; return; }

    // int fullReset = 0;
    // if (n > a) fullReset += (n - 1 + a) / a;
    // else fullReset += (a - 1 + n) / n;
    // if (m > b) fullReset += (m - 1 + b) / b;
    // else fullReset += (b - 1 + m) / m;
    
    // if (fullReset % 2 == 0) cout << "YES\n";
    // else cout << "NO\n";

    cout << (gcd(n, m) == 2 || gcd(n, m) == 1 ? "YES\n" : "NO\n");
}

const int TESTCASES = 1;
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