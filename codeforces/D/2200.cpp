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

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vi a(n); cin >> a;

    auto ret = [](vector<int> mid) -> vector<int> {
        int n = mid.size();
        mid.insert(mid.end(), mid.begin(), mid.end());
        int idx = 0;
        int mn = *min_element(mid.begin(), mid.end());
        while (mid[idx] != mn) idx++;

        vector<int> vec;
        for (int i = idx; i < n + idx; i++) vec.push_back(mid[i]);
        return vec;
    };

    vector<int> mid, others;
    for (int i = 0; i < n; i++) {
        if (i < x) others.push_back(a[i]);
        else if (i < y) mid.push_back(a[i]);
        else others.push_back(a[i]);
    }

    mid = ret(mid);
    int idx = others.size();
    n = others.size();
    for (int i = 0; i < n; i++) if (others[i] > mid[0]) { idx = i; break; }

    vector<int> ans;
    for (int i = 0; i < idx; i++) ans.push_back(others[i]);
    for (int i = 0; i < mid.size(); i++) ans.push_back(mid[i]);
    for (int i = idx; i < n; i++) ans.push_back(others[i]);

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
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}