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

// void solve() {
//     int n, k1, k2; cin >> n >> k1 >> k2;
//     int k = k1 + k2;

//     vector<int> a(n);
//     vector<int> b(n);
//     cin >> a >> b;

//     priority_queue<int> c;
//     for (int i = 0; i < n; ++i) c.push(abs(a[i] - b[i]));

//     while (k && c.top()) {
//         k--;
//         int mx = c.top();
//         c.pop();
//         c.push(mx - 1);
//     }

//     k %= 2;
//     if (k) {
//         int mx = c.top();
//         c.pop();
//         c.push(mx + 1);
//     }

//     int ans = 0;
//     int cur = 0;
//     for (int i = 0; i < n; ++i) {
//         cur = c.top();
//         ans += cur * cur;
//         c.pop();
//     }

//     cout << ans << endl;
// }

void solve() {
    int n, k1, k2; cin >> n >> k1 >> k2;
    int k = k1 + k2;
    vector<int> a(n), b(n); cin >> a >> b;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) c[i] = (abs(a[i] - b[i]));

    sort(all(c));

    while (k) {
        int mx = c[n - 1];

        if (mx == 0) break;
        
        int l = lower_bound(all(c), mx) - c.begin();
        int r = upper_bound(all(c), mx) - c.begin();

        int numberOfOperations = min(r - l, k);
        k -= numberOfOperations;

        int idx = n - 1;
        while (numberOfOperations--) c[idx--]--;

        sort(all(c));
    }

    k %= 2;

    if (k) c[n - 1]++;

    int ans = 0;
    for (int i = 0; i < n; ++i) ans += c[i] * c[i];

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
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