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

int calc(vector<int> & a, int end) {
    int n = a.size();
    int longestDis = 0, longDis = 0;
    for (int i = 0; i <= n; i++) {
        int cur = (i == n ? end : a[i]) - (i ? a[i - 1] : 0) - 1;
        if (cur > longestDis) {
            longDis = longestDis;
            longestDis = cur;
        } else if (cur > longDis) longDis = cur;
    }

    int ret = max(longestDis / 2, longDis);
    return ret;
}

void solve() {
    int n, k; cin >> n >> k;
    vi c(n); cin >> c;
    vi a[k + 1];
    for (int i = 0; i < n; i++) a[c[i]].push_back(i + 1);


    int ans = LLONG_MAX;
    for (int i = 1; i <= k; i++) ans = min(ans, calc(a[i], n + 1));

    cout << ans << endl;
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