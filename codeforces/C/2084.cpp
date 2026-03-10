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

int x;
bool firstCheck(int n, const vector<int> & a, const vector<int> & b, const vector<int> & pos) {
    x = 0;
    for (int i = 1; i <= n; ++i) if (a[i] == b[i]) {
        if (n % 2 == 0 || x) return true;
        x = i;
    }
    else if (b[pos[b[i]]] != a[i]) return true;
    return false;
}

vector<array<int, 2>> ans(3e6);
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) cin >> b[i];

    if (firstCheck(n, a, b, pos)) { cout << "-1\n"; return; }

    int cnt = 0;
    auto swapper = [&](int x, int y) -> void {
        if (x == y) return;
        cnt++;
        ans[cnt][0] = x;
        ans[cnt][1] = y;
        swap(a[x], a[y]);
        swap(pos[a[x]], pos[a[y]]);
        swap(b[x], b[y]);
    };
    if (n % 2) swapper(x, (n + 1) / 2);
    for (int i = 1; i <= n / 2; ++i) swapper(pos[b[i]], n + 1 - i);

    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i) cout << ans[i][0] << ' ' << ans[i][1] << endl;
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