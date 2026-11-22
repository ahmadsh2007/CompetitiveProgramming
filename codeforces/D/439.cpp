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
    int n, m; cin >> n >> m;
    vector<int> a(n); cin >> a;
    vector<int> b(m); cin >> b;
    sort(all(a));
    sort(all(b));

    vector<int> pre(n), suf(m);
    pre[0] = a[0];
    suf[m - 1] = b[m - 1];
    for (int i = 1; i < n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = m - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] + b[i];
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, a[i]);
    }
    for (int i = 0; i < m; ++i) {
        mx = max(mx, b[i]);
    }

    int res[2] = {0, 0};
    auto check = [&](int m1, int m2) -> bool {
        res[0] = res[1] = 0;
        int it[2];
        it[0] = upper_bound(all(a), m1) - a.begin() - 1;
        it[1] = lower_bound(all(b), m1) - b.begin();
        if (it[0] >= 0) {
            res[0] += (it[0] + 1) * m1 - pre[it[0]];
        }
        if (it[1] < m) {
            res[0] += suf[it[1]] - (m - it[1]) * m1; 
        }

        it[0] = upper_bound(all(a), m2) - a.begin() - 1;
        it[1] = lower_bound(all(b), m2) - b.begin();
        if (it[0] >= 0) {
            res[1] += (it[0] + 1) * m2 - pre[it[0]];
        }
        if (it[1] < m) {
            res[1] += suf[it[1]] - (m - it[1]) * m2;
        }

        return res[0] <= res[1];
    };

    int l = 0, r = mx;
    int m1, m2, ans = LLONG_MAX;
    while (l <= r) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        if (check(m1, m2)) {
            r = m2 - 1;
        }
        else l = m1 + 1;

        ans = min({ans, res[0], res[1]});
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