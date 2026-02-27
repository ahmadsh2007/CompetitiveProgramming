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

vector<int> ret(vector<int> mid) {
    int n = mid.size();
    mid.insert(mid.end(), all(mid));
    int idx = 0;
    int mn = *min_element(all(mid));
    while (mid[idx] != mn) idx++;
    vector<int> retV;
    for (int i = idx; i < n + idx; i++) retV.push_back(mid[i]);
    return retV;
}

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vi a(n); cin >> a;

    if (x == 0 && y == n) {
        a.insert(a.end(), all(a));
        int idx = 0;
        while (a[idx] != 1) idx++;
        for (int i = idx; i < n + idx; i++) cout << a[i] << " \n"[i == n - 1 + idx];
        return;
    }

    vector<int> left, mid, right;
    for (int i = 0; i < n; i++) {
        if (i < x) left.push_back(a[i]);
        else if (i < y) mid.push_back(a[i]);
        else right.push_back(a[i]);
    }

    mid = ret(mid);

    vi ans;
    for (int x : left) ans.push_back(x);
    for (int x :right) ans.push_back(x);

    int spliter = ans.size();
    for (int i = 0; i < ans.size(); i++) if (ans[i] > mid[0]) { spliter = i; break; }

    for (int i = 0; i < spliter; i++) cout << ans[i] << ' ';
    for (int val : mid) cout << val << ' ';
    for (int i = spliter; i < ans.size(); i++) cout << ans[i] << " \n"[i == ans.size() - 1];
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
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}