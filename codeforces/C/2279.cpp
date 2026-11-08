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

    if (ell == 1) {
        return void(cout << accumulate(all(a), 0ll) - a[n - 1] << endl);
    }
    else if (a[n - 1] * a[n - 2] < ell) {
        return void(cout << 0 << endl);
    }

    int x1 = a[n - 1];
    int x2 = 1;
    while ((x2 + 1) * (x2 + 1) < ell) x2++;
    int st = n - 2;
    int cur = 0;
    auto mx = [&](int x) -> int {
        if (x == 0) return 0;
        return max(0ll, x1 - (ell - 1) / x);
    };

    while (st >= 0 and a[st] >= x2) {
        cur += (a[st] - x2);
        st--;
    }

    int ans = cur + mx(x2--);
    for (; x2 >= 0; --x2) {
        cur += (n - 2 - st);
        while (st >= 0 and a[st] >= x2) {
            st--;
        }

        ans = min(ans, cur + mx(x2));
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