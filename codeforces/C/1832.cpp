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

// void solve() {
//     int n; cin >> n;
//     vi temp(n); cin >> temp;

//     bool same = 1;
//     for (int i = 1; i < n; i++) if (temp[i] != temp[i - 1]) { same = 0; break; }
//     if (same) { cout << "1\n"; return; }

//     vi a{temp[0]};
//     for (int i = 1; i < n; i++) if (temp[i] != temp[i - 1]) a.push_back(temp[i]);

//     vi ans{a[0]};
//     bool up = (a[1] >= a[0]);
//     int cur = a[0];
//     for (int i = 1; i < a.size(); i++) {
//         if (up)
//         {
//             if (a[i] < cur) {
//                 ans.push_back(a[i]);
//                 up = 0;
//             }
//             cur = a[i];
//         }
//         else
//         {
//             if (a[i] > cur) {
//                 ans.push_back(a[i]);
//                 up = 1;
//             }
//             cur = a[i];
//         }
//     }

//     cout << ans.size() + 1 << endl;
// }

void solve() {
    // Solution 2 based on what I understood from the problem statement
    int n; cin >> n;
    vi a(n); cin >> a;

    int ans = n = unique(all(a)) - a.begin();
    for (int i = 1; i < n - 1; i++) {
        if (a[i + 1] < a[i] && a[i] < a[i - 1]) ans--;
        if (a[i + 1] > a[i] && a[i] > a[i - 1]) ans--;
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
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