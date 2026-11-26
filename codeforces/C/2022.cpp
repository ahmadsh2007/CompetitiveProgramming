/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

template<class T>istream& operator>>(istream& in, vector<T>& v){for(auto& x:v) in>>x;return in;}
template<class T>ostream& operator<<(ostream& out, vector<T>& v){for(auto& x:v) out<<x<<' ';return out;}

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const long long INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    string s[2]; cin >> s[0] >> s[1];

    auto a = [&](int r, int c) { return (int)(s[r][c] == 'A'); };
    auto v = [&](int x, int y, int z) { return (int)(x + y + z >= 2); };

    const long long NEG = -INF;
    vector<array<int, 3>> dp(n + 4, {NEG, NEG, NEG});
    dp[0][0] = 0;
    for (int j = 0; j < n; ++j) {
        if (dp[j][0] > NEG) {
            int c = dp[j][0];
            if (j + 1 < n) {
                dp[j + 1][1] = max(dp[j + 1][1], c + v(a(0, j), a(1, j), a(0, j + 1)));
                dp[j + 1][2] = max(dp[j + 1][2], c + v(a(0, j), a(1, j), a(1, j + 1)));
            }
            if (j + 2 < n)
                dp[j + 3][0] = max(dp[j + 3][0], c + v(a(0, j), a(0, j + 1), a(0, j + 2)) + v(a(1, j), a(1, j + 1), a(1, j + 2)));
        }
        if (dp[j][1] > NEG) {
            int c = dp[j][1];
            if (j + 1 < n) {
                dp[j + 2][0] = max(dp[j + 2][0], c + v(a(1, j), a(1, j + 1), a(0, j + 1)));
            }
            if (j + 3 < n) {
                dp[j + 3][1] = max(dp[j + 3][1], c + v(a(0, j + 1), a(0, j + 2), a(0, j + 3)) + v(a(1, j), a(1, j + 1), a(1, j + 2)));
            }
        }
        if (dp[j][2] > NEG) {
            int c = dp[j][2];
            if (j + 1 < n) {
                dp[j + 2][0] = max(dp[j + 2][0], c + v(a(0, j), a(0, j + 1), a(1, j + 1)));
            }
            if (j + 3 < n) {
                dp[j + 3][2] = max(dp[j + 3][2], c + v(a(1, j + 1), a(1, j + 2), a(1, j + 3)) + v(a(0, j), a(0, j + 1), a(0, j + 2)));
            }
        }
    }
    
    cout << dp[n][0] << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}