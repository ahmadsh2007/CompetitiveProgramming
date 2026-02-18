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

bool check(const vector<vector<int>> & prefix, int l, int k, int r) {
    int value = 0;
    for (int i = 32; i >= 0; i--) {
        if (prefix[r][i] - prefix[l - 1][i] == r + 1 - l) value += (1ll << i);
    }

    return value >= k;
}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    vector<vector<int>> prefix(n + 1, vector<int>(33));
    for (int i = 0; i < n; i++) {
        vector<int> bits(33);
        for (int j = 32; j >= 0; j--) {
            if (a[i] & (1ll << j)) bits[j] = 1;
        }

        for (int j = 0; j < 33; j++) prefix[i + 1][j] = prefix[i][j] + bits[j];
    }

    int q; cin >> q;
    while(q--) {
        int ans = -1;
        int st, k; cin >> st >> k;

        int quickCheck = a[st - 1];
        if (quickCheck < k) { cout << -1 << " \n"[q == 0]; continue; }

        int l = st, r = n, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (check(prefix, st, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        cout << ans << " \n"[q == 0];
    }
}

const int TESTCASES = 1;
signed main() {
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