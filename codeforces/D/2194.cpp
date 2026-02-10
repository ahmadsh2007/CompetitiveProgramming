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

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    int cnt = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) cnt++;
            cin >> a[i][j];
        }

    for (int i = 0; i < n; i++) for (int j = 1; j < m; j++) a[i][j] += a[i][j - 1];

    vector<int> prefix(n + 1);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i][m - 1];

    int idx = 0;
    while (prefix[++idx] < prefix[n] / 2);
    idx--;

    vector<int> suffix(m + 1);
    for (int i = m - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + (a[idx][i] - (i - 1 < 0 ? 0LL : a[idx][i - 1]));

    int nn = n, mm = m;
    int ans = (prefix[nn] / 2) * ((prefix[nn] + 1) / 2);
    str s;
    for (int i = 0; i < idx; i++) s += "D";
    n -= idx;
    int r = 0;
    while (prefix[idx] + suffix[r] > prefix[nn] / 2) r++;
    for (int i = 0; i < r; i++) s += "R";
    m -= r;
    s += "D", n--;
    for (int i = 0; i < m; i++) s += "R";
    for (int i = 0; i < n; i++) s += "D";

    cout << ans << endl;
    cout << s << endl;
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