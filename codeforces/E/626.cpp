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
    vector<int> x(n);
    for (auto &it : x) cin >> it;

    sort(all(x));

    vector<int> pre(n), suf(n);
    pre[0] = x[0];
    suf[n - 1] = x[n - 1];
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + x[i];
    for (int i = n - 2; i >= 0; --i) suf[i] = suf[i + 1] + x[i];

    auto f = [&](int i, int k) {
        int s = pre[i] - (i - k - 1 >= 0 ? pre[i - k - 1] : 0);
        if (k) s += suf[n - k];
        return s;
    };

    int bi = 0, bk = 0, bn = 0, bd = 1;
    for (int i = 0; i < n; ++i) {
        int l = 0, r = min(i, n - 1 - i);
        int m1, m2, ans = 0;
        while (l <= r) {
            m1 = l + (r - l) / 3;
            m2 = r - (r - l) / 3;
            int f1 = f(i, m1) * (2 * m2 + 1);
            int f2 = f(i, m2) * (2 * m1 + 1);
            if (f1 < f2) {
                l = m1 + 1;
                ans = m2;
            }
            else {
                r = m2 - 1;
                ans = m1;
            }
        }

        int d = 2 * ans + 1, num = f(i, ans) - x[i] * d;
        if (num * bd > bn * d) {
            bn = num;
            bd = d;
            bi = i;
            bk = ans;
        }
    }

    cout << 2 * bk + 1 << endl;
    for (int j = bi - bk; j <= bi; ++j) cout << x[j] << ' ';
    for (int j = n - bk; j < n; ++j) cout << x[j] << ' ';
    cout << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}