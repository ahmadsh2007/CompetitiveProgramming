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
    vector<int> a(n); cin >> a;
    int ind = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (abs(a[i] - a[i + 1]) > abs(a[ind] - a[ind + 1])) {
            ind = i;
        }
    }

    vector<int> pre(n + 1, 0), suf(n + 1, 0);
    for (int i = 1; i < n; ++i) pre[i] = max(pre[i - 1], abs(a[i - 1] - a[i]));
    for (int i = n - 2; i >= 0; --i) suf[i] = max(suf[i + 1], abs(a[i] - a[i + 1]));

    int ans = 0;
    for (int i = 1; i < n; ++i) {
        ans = max(ans, abs(a[i] - a[i - 1]));
    }
    auto checkLeft = [&]() -> void {
        int diffInsideTheArray = 0;
        int cur = ans;
        int switchWith = -1;
        for (int i = ind; i >= 0; --i) {
            if (i != ind) {
                diffInsideTheArray = max(diffInsideTheArray, abs(a[i] - a[i + 1]) * 2);
            }
            int temp = max({diffInsideTheArray, abs(2 * a[i] - a[ind + 1]), abs(2 * a[ind] - (i != 0 ? a[i - 1] : 2 * a[ind])), pre[max(i - 1, 0ll)], suf[ind + 1]});
            if (temp < cur) {
                switchWith = i;
                cur = temp;
            }
        }

        if (switchWith == -1) {
            return;
        }
        vector<int> b = a;
        reverse(b.begin() + switchWith, b.begin() + ind + 1);
        for (int i = switchWith; i <= ind; ++i) b[i] *= 2;
        cur = 0;
        for (int i = 1; i < n; ++i) {
            cur = max(cur, abs(b[i] - b[i - 1]));
        }
        ans = min(ans, cur);
    };
    auto checkRight = [&]() -> void {
        int diffInsideTheArray = 0;
        int cur = ans;
        int switchWith = -1;
        for (int i = ind + 1; i < n; ++i) {
            if (i != ind + 1) {
                diffInsideTheArray = max(diffInsideTheArray, abs(a[i] - a[i - 1]) * 2);
            }
            int temp = max({diffInsideTheArray, abs(2 * a[i] - a[ind]), abs(2 * a[ind + 1] - (i != n - 1 ? a[i + 1] : 2 * a[ind + 1])), pre[ind], suf[i + 1]});
            if (temp < cur) {
                switchWith = i;
                cur = temp;
            }
        }

        if (switchWith == -1) {
            return;
        }
        vector<int> b = a;
        reverse(b.begin() + ind + 1, b.begin() + switchWith + 1);
        for (int i = ind + 1; i <= switchWith; ++i) b[i] *= 2;
        cur = 0;
        for (int i = 1; i < n; ++i) {
            cur = max(cur, abs(b[i] - b[i - 1]));
        }
        ans = min(ans, cur);
    };

    checkLeft();
    checkRight();

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