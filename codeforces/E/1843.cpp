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

// struct Segment {
//     int l, r, cnt = 0;
//     bool operator<(const Segment& other) const {
//         if (l != other.l) return l < other.l;
//         return r < other.r;
//     }
//     bool operator==(const Segment& other) const {
//         return l == other.l && r == other.r;
//     }
// };

void solve() {
    int n, m; cin >> n >> m;
    vector<int> pref(n + 2);
    vector<pair<int, int>> segs(m);
    for (int i = 0; i < m; ++i) cin >> segs[i].first >> segs[i].second;

    int q; cin >> q;
    vector<int> x(q); cin >> x;

    auto check = [&](int mid) -> bool {
        for (int i = 0; i < n + 2; ++i) pref[i] = 0;
        for (int i = 0; i < mid; ++i) pref[x[i]] = 1;
        for (int i = 1; i <= n; ++i) pref[i] += pref[i - 1];
        
        for (int i = 0; i < m; ++i) {
            int l = segs[i].first;
            int r = segs[i].second;
            int len = r - l + 1;
            int cnt = pref[r] - pref[l - 1];
            if (cnt * 2 > len) return true;
        }
        return false;
    };

    int l = 0, r = q, mid, ans = -1;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans << endl;
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