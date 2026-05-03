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

const int N = 1e6;
vector<bool> isPrime;
vector<bool> sieve(int n){vector<bool> p(n+1,true);if(n>=0)p[0]=0;if(n>=1)p[1]=0;for(int i=2;i*i<=n;i++)if(p[i])for(int j=i*i;j<=n;j+=i)p[j]=0;return p;}

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    int g = 0;
    for (int i = 0; i < n; ++i) g = gcd(g, a[i]);

    if (g != 1) { cout << "-1\n"; return; }

    bool haveOne = 0;
    for (int i = 0; i < n; ++i) if (a[i] == 1) { haveOne = 1; break; }

    if (haveOne) {
        int ans = 0;
        for (int i = 0; i < n; ++i) if (a[i] != 1) ans++;

        cout << ans << endl;
    }
    else {
        int cur = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (gcd(a[i], a[j]) == 1) cur = min(cur, j - i);
            }
        }

        if (cur == LLONG_MAX) cout << n + 1 << endl;
        else cout << cur + n - 1 << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    isPrime = sieve(N);

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