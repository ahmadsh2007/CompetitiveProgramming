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
    int n, m, k; cin >> n >> m >> k;
    vi a(n); cin >> a;
    vi b(m); cin >> b;

    vector<int> fa(n + 1), fb(m + 1);
    
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) fa[++cnt]++;
        else cnt = 0;
    }

    cnt = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] == 1) fb[++cnt]++;
        else cnt = 0;
    }

    for (int i = n - 1; i; --i) fa[i] += fa[i + 1];
    for (int i = m - 1; i; --i) fb[i] += fb[i + 1];

    int ans = 0;
    for (int i = 1; i * i <= k; ++i) {
        if (k % i == 0) {
            int j = k / i;
            if (i <= n && j <= m) ans += fa[i] * fb[j];
            if (i != j && j <= n && i <= m) ans += fb[i] * fa[j];
        }
    }

    cout << ans << endl;
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
    #ifndef local
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}