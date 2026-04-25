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

int n, median;
vector<int> a(5000), dp(5000);

bool check(const vector<int> & cnt) {
    return (abs(cnt[0] - cnt[2]) < cnt[1] && (cnt[0] + cnt[1] + cnt[2]) % 2);
}

int solve(int index) {
    if (index == n) return 0;
    if (dp[index] != -1e9) return dp[index];
    
    int mx = -1e9;
    
    vector<int> cnt(3);

    for (int i = index; i < n; ++i) {
        cnt[0] += (a[i] < median);
        cnt[1] += (a[i] == median);
        cnt[2] += (a[i] > median);

        if (check(cnt)) {
            int value = solve(i + 1);
            if (value != -1) mx = max(mx, value + 1);
        }
    }

    if (mx == -1e9) mx = -1;
    return dp[index] = mx;
}

void solve() {
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        dp[i] = -1e9;
    }

    sort(all(b));
    median = b[n / 2];

    cout << solve(0) << endl;
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