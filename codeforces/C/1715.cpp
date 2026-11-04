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
    int n, q; cin >> n >> q;
    vector<int> a(n); cin >> a;

    int ans = n * (n + 1) / 2;

    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            ans += i * (n - i);
        }
    }

    while (q--) {
        int i, x; cin >> i >> x;
        i--;

        if (i > 0 and a[i] != a[i - 1]) {
            ans -= i * (n - i);
        }
        if (i < n - 1 and a[i] != a[i + 1]) {
            ans -= (i + 1) * (n - (i + 1));
        }

        a[i] = x;
        if (i > 0 and a[i] != a[i - 1]) {
            ans += i * (n - i);
        }
        if (i < n - 1 and a[i] != a[i + 1]) {
            ans += (i + 1) * (n - (i + 1));
        }

        cout << ans << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}