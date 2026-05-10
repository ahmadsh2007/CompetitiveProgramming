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
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[i] = (x <= k ? 1 : -1);
    }

    vector<int> suf(n), minSuf(n);
    auto check = [&]() -> bool {
        suf[n - 1] = minSuf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = suf[i + 1] + a[i];
            minSuf[i] = min(minSuf[i + 1], suf[i]);
        }

        int sum = 0;
        for (int i = 0; i + 2 < n; ++i) {
            sum += a[i];
            if (sum >= 0 && suf[i + 1] >= minSuf[i + 2]) return true;
        }

        return 0;
    };

    int L = n, R = -1, curSum = 0;
    for (int i = 0; i < n; ++i) {
        curSum += a[i];
        if (curSum >= 0) {
            L = i;
            break;
        }
    }

    curSum = 0;
    for (int i = n - 1; i >= 0; --i) {
        curSum += a[i];
        if (curSum >= 0) {
            R = i;
            break;
        }
    }

    if (L + 1 < R) { cout << "YES\n"; return; }
    if (check()) { cout << "YES\n"; return; }
    reverse(all(a));
    if (check()) { cout << "YES\n"; return; }
    cout << "NO\n";
}

const int TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef LOCAL
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}