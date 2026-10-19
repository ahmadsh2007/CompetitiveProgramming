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

const int N = 1e6;
vector<vector<int>> divs(N + 1);
static const int DIVS = []() {
    for (int d = 1; d <= N; ++d) {
        for (int k = d; k <= N; k += d) {
            divs[k].push_back(d);
        }
    }
    return 0;
}();

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n); cin >> a;
    sort(all(a));

    vector<int> cnt(m + 1);
    int covered = 0, ans = LLONG_MAX;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        for (int d : divs[a[r]]) {
            if (d > m) break;
            if (cnt[d]++ == 0) covered++;
        }
        while (covered == m) {
            ans = min(ans, a[r] - a[l]);
            for (int d : divs[a[l]]) {
                if (d > m) break;
                if (--cnt[d] == 0) covered--;
            }
            l++;
        }
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