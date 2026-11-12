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
    vector<int> a(n + 1), P(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        P[i] = P[i - 1] + a[i];
    }

    vector<array<int, 2>> pre(n + 1), suf(n + 1);
    pre[0] = {P[0], P[0]};
    suf[n] = {P[n], P[n]};
    for (int i = 1; i <= n; ++i) {
        pre[i] = {min(pre[i - 1][0], P[i]), max(pre[i - 1][1], P[i])};
    }
    for (int i = n - 1; i >= 1; --i) {
        suf[i] = {min(suf[i + 1][0], P[i]), max(suf[i + 1][1], P[i])};
    }

    int ans = pre[n][1] - pre[n][0] + 1;
    for (int i = 1; i <= n; ++i) {
        int d  = 2 * a[i];
        int l = min(pre[i - 1][0], suf[i][0] - d);
        int r = max(pre[i - 1][1], suf[i][1] - d);
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}