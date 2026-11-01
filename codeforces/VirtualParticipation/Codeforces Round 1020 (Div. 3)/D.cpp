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
    int n, m; cin >> n >> m;
    vector<int> a(n); cin >> a;
    vector<int> b(m); cin >> b;

    vector<int> pre(n + 2), suf(n + 2);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (pre[i] < m and a[i] >= b[pre[i]]);
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + (suf[i + 1] < m and a[i] >= b[m - 1 - suf[i + 1]]);
    }

    if (pre[n] >= m) {
        return void(cout << 0 << endl);
    }

    int ans = LLONG_MAX;
    for (int i = 0; i <= n; ++i) {
        if (pre[i] + suf[i] >= m - 1) ans = min(ans, b[pre[i]]);
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}