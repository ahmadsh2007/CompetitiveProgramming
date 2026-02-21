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
    int n, h, k; cin >> n >> h >> k;
    vi a(n); cin >> a;

    int tot = accumulate(all(a), 0ll);
    int needed = h % tot;
    int m = h / tot;

    int ans;
    if (needed == 0) ans = max(m * (n + k) - k, 0ll);
    else ans = m * (n + k);

    if (needed == 0) { cout << ans << endl; return; }

    
    vi prefixMn(n + 1, LLONG_MAX);
    for (int i = 0; i < n; i++) prefixMn[i + 1] = min(prefixMn[i], a[i]);
    
    vi suffixMx(n + 1, LLONG_MIN);
    for (int i = n - 1; i; i--) suffixMx[i] = max(suffixMx[i + 1], a[i]);
    for (int i = 1; i < n; i++) a[i] += a[i - 1];

    for (int i = 0; i < n; i++) {
        int best = a[i];
        best = max(best, a[i] - prefixMn[i + 1] + suffixMx[i + 1]);

        if (best < needed) continue;
        ans += i + 1;
        break;
    }

    cout << ans << endl;
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
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}