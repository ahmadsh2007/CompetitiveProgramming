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

struct Seg {
    int l, r;
    int i;
};

void solve() {
    int n; cin >> n;
    vector<Seg> a(n + 1);
    for (int i = 1; i <= n; ++i) {  
        int x, y; cin >> x >> y;
        a[i].l = x;
        a[i].r = y;
        a[i].i = i;
    }

    sort(all(a), [](const Seg & s1, const Seg & s2) {
        if (s1.l == s2.l) return s1.r > s2.r;
        return s1.l < s2.l;
    });

    bool DEBUGMODE = 0;
    if (DEBUGMODE) {
        for (int i = 1; i <= n; ++i) {
            cout << a[i].l << ' ' << a[i].r << " Index: " << a[i].i << endl;
        }

        return;
    }

    int mx = a[1].r, ind = a[1].i;
    for (int i = 2; i <= n; ++i) {
        if (mx >= a[i].r) {
            cout << a[i].i << ' ' << ind << endl;
            return;
        }

        if (a[i].r > mx) {
            mx = a[i].r;
            ind = a[i].i;
        }
    }

    cout << "-1 -1\n";
}

const int TESTCASES = 0;
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