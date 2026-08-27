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
#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, k; cin >> n >> k;
    map<int, vector<int>> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x % k].push_back(x);
    }

    int oddCnt = 0;
    for (auto &[rem, v] : a) {
        sort(all(v));
        if (v.size() & 1) oddCnt++;
    }

    if (oddCnt > (n & 1)) {
        return void(cout << -1 << endl);
    }

    int ans = 0;
    for (auto &[rem, v] : a) {
        int sz = (int) v.size();
        if (sz % 2 == 0) {
            for (int i = 0; i < sz; i += 2) {
                ans += (v[i + 1] - v[i]) / k;
            }
        }
        else {
            vector<int> pre(sz), suf(sz);
            for (int i = 1; i < sz; i += 2) {
                pre[i] = (v[i] - v[i - 1]) / k;
                if (i >= 2) pre[i] += pre[i - 2];
            }
            for (int i = sz - 2; i >= 0; i -= 2) {
                suf[i] = (v[i + 1] - v[i]) / k;
                if (i + 2 < sz) suf[i] += suf[i + 2];
            }

            int best = INF;
            for (int i = 0; i < sz; i += 2) {
                int cur = 0;
                if (i > 0) cur += pre[i - 1];
                if (i + 1 < sz) cur += suf[i + 1];
                best = min(best, cur);
            }
            ans += best;
        }
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