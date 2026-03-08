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

const int noAns = 4000000000000000000LL;
void solve() {
    int n, h; cin >> n >> h;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1));
    vector<vector<int>> suffix(n + 1, vector<int>(n + 1));
    vector<vector<int>> maxIdx(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        int cur = a[i];
        int sum = 0;
        for (int j = i; j <= n; ++j) {
            if (a[j] > cur) cur = a[j];
            sum += cur;
            prefix[i][j] = sum;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur = a[i];
        int sum = 0;
        for (int j = i; j >= 1; --j) {
            if (a[j] > cur) cur = a[j];
            sum += cur;
            suffix[j][i] = sum;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int best = i;
        int cur = a[i];
        maxIdx[i][i] = i;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] > cur) {
                cur = a[j];
                best = j;
            }
            maxIdx[i][j] = best;
        }
    }

    int mn = noAns;
    auto getPrefix = [&](int k, int l, int r) -> int {
        if (l > r) return 0;
        int ans = prefix[k][r];
        if (l > k) ans -= prefix[k][l - 1];
        return ans;
    };
    auto getSuffix = [&](int k, int l, int r) -> int {
        if (l > r) return 0;
        int ans = suffix[l][k];
        if (r < k) ans -= suffix[r + 1][k];
        return ans;
    };

    for (int i = 1; i <= n; i++) if (a[i] < h) {
        int cost = suffix[1][i] + prefix[i][n] - a[i];
        if (cost < mn) mn = cost;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == h) continue;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] == h) continue;
            int idx = maxIdx[i][j];
            int cost = suffix[1][i] + getPrefix(i, i + 1, idx) + getSuffix(j, idx + 1, j - 1) + prefix[j][n];
                           
            if (cost < mn) mn = cost;
        }
    }

    if (mn == noAns) cout << 0 << endl;
    else cout << n * h - mn << endl;
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