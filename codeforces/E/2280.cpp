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
    int n, ell; cin >> n >> ell;
    vector<int> a(n); cin >> a;
    sort(all(a));

    if (ell == 0) {
        return void(cout << accumulate(all(a), 0ll) - a[n - 1] << endl);
    }
    if (a[n - 1] * a[n - 2] < ell) {
        return void(cout << 0 << endl);
    }

    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }
    int ans = LLONG_MAX;
    for (int k = 0; k * k < ell; ++k) {
        int idx = lower_bound(a.begin(), a.begin() + n - 1, k) - a.begin();

        // cost[0]: cost of reducing all elements [1..n - 1] to k
        // cost[1]: cost of reducing a[n] to an acceptable value
        int cost[2];
        cost[0] = pre[n - 1] - pre[idx] - k * (n - 1 - idx);
        cost[1] = (k ? max(0ll, a[n - 1] - (ell - 1) / k) : 0ll);
        ans = min(ans, cost[0] + cost[1]);
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