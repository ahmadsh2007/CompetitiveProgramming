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

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n); cin >> a;
    vector<int> b(n); cin >> b;

    vector<vector<int>> dp(n, vector<int>(2));
    dp[n - 1][0] = dp[n - 1][1] = (a[n - 1] == b[n - 1] ? 2 : 1);
    for (int i = n - 2; i >= 0; --i) {
        dp[i][0] = dp[i + 1][1] + (a[i] == b[i + 1] ? 2 : 1) + (a[i + 1] == b[i] ? 2 : 1);
        dp[i][1] = dp[i + 1][0] + (a[i] == b[i + 1] ? 2 : 1) + (a[i + 1] == b[i] ? 2 : 1);
    }

    int cur = 0;
    int ans = dp[0][0];
    for (int k = 1; k < n; ++k) {
        cur += (a[k - 1] == b[k - 1] ? 2 : 1) + (a[k] == b[k - 1] ? 2 : 1);
        ans = max(ans, cur + dp[k][0]);
    }
    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}