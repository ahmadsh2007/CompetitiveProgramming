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

int n, k;
vi a, b;
bool check(int cookie) {
    __int128 need = 0;
    for (int i = 0; i < n; ++i) {
        __int128 x = a[i];
        __int128 y = b[i];
        if (x * cookie - y > 0) need += x * cookie - y;
    }

    return need <= k;
}

// bool check(int cookie) {
//     int need = 0;
//     for (int i = 0; i < n; ++i) {
//         int x = a[i];
//         int y = b[i];
//         if ((x * cookie - y) > 0) {
//             int z = LLONG_MAX - need;
//             if ((x * cookie - y) > z) return false; 
//             need += (x * cookie - y);
//         }
//     }

//     return need <= k;
// }

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    b.assign(n, 0);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    int l = 0, r = (int) 1e10, mid, ans = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    while (TTT--) solve();
    return 0;
}