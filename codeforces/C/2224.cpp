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
    int n; cin >> n;
    str s; cin >> s;
    str t; cin >> t;

    int cnt = 0;
    for (int i = 0; i < n; ++i) cnt += (s[i] == ')' ? 1 : -1) + (t[i] == ')' ? 1 : -1);

    if (cnt != 0) { cout << "NO\n"; return; }

    auto check = [&](str &s, str &t) -> bool {
        int balance[2] = {0, 0};
        for (int i = 0; i < n; ++i) {
            int cnt = (s[i] == '(') + (t[i] == '(');
            if (cnt == 2) for (int i = 0; i < 2; ++i) balance[i]++;
            else if (cnt == 0) for (int i = 0; i < 2; ++i) balance[i]--;
            else {
                sort(balance, balance + 2);
                balance[0]++;
                balance[1]--;
            }

            for (int i = 0; i < 2; ++i) if (balance[i] < 0) return false;
        }

        return (balance[0] == 0 && balance[1] == 0);
    };

    cout << (check(s, t) ? "YES\n" : "NO\n");
}

const int TESTCASES = 1;
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