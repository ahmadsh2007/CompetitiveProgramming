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
    int n, A, R, M; cin >> n >> A >> R >> M;
    vector<int> h(n); cin >> h;
    sort(all(h));

    auto f = [&](int x) -> int {
        int add = 0;
        int rem = 0;
        for (int i = 0; i < n; ++i) {
            if (h[i] == x) {
                continue;
            }

            if (h[i] < x) {
                add += x - h[i];
            }
            if (h[i] > x) {
                rem += h[i] - x;
            }
        }

        int res = 0;
        int mv = min(M, A + R);
        int mn = min(add, rem);
        res += mv * mn;
        res += A * (add - mn);
        res += R * (rem - mn);

        return res;
    };

    int l = h[0], r = h[n - 1];
    int m1, m2, ans = LLONG_MAX;
    while (l <= r) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        int val[2] = {f(m1), f(m2)};
        ans = min({ans, val[0], val[1]});
        if (val[0] < val[1]) r = m2 - 1;
        else l = m1 + 1;
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