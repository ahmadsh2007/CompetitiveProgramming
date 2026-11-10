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
    int k, l1, r1, l2, r2; cin >> k >> l1 >> r1 >> l2 >> r2;
    int ans = 0;
    for (int cur = 1; cur <= r2; cur *= k) {
        int mn = r1 + 1;
        int l = l1, r = r1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid * cur >= l2) {
                mn = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        int mx = l1 - 1;
        l = l1, r = r1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (mid * cur <= r2) {
                mx = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        ans += max(0LL, mx - mn + 1);
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