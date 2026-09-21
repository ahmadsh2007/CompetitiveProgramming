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

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 1e6;
vector<int> primes, spf(N+1);
static const int PrimesAndSPF=[](){
    for(int i=2;i<=N;i++){ if(!spf[i]) spf[i]=i,primes.push_back(i); for(int p:primes){ if(1LL*p*i>N) break; spf[p*i]=p; if(p==spf[i]) break; } } return 0;
}();

vector<int> dp(2e5 + 10, -1);
vector<int> vis(2e5 + 10, 0);
int timer = 0;
int n, k;
int check(int x, vector<int> & dp) {
    if (x <= k) return 0ll;
    if (vis[x] == timer) return dp[x];
    int xx = x;
    int ans = LLONG_MAX;
    while (xx != 1) {
        int p = spf[xx];
        ans = min(ans, 1 + p * check(x / p, dp));
        while (xx % p == 0) xx /= p;
    }
    vis[x] = timer;
    return dp[x] = ans;
}

void solve() {
    cin >> n >> k;
    vector<int> a(n); cin >> a;
    
    timer++;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += check(a[i], dp);
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}