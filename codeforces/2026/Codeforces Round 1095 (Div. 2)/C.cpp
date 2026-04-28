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

bool check(const vector<int> & a, int n, int m) {
    vector<int> needed(m + 1, 1);
    vector<int> have;

    for (int i = 0; i < n; ++i) {
        if (a[i] < m && needed[a[i]]) needed[a[i]] = 0;
        else have.push_back(a[i]);
    }

    int ptr = (int) have.size() - 1;

    for (int i = m - 1; i >= 0; --i) {
        if (needed[i] && ptr < 0) return 0;
        if (needed[i] && have[ptr] - 1 < 2 * i) return 0;
        if (needed[i]) ptr--;
    }

    return true;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    sort(all(a));

    int l = 0, r = n, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(a, n, mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
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
    #ifndef LOCAL
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}