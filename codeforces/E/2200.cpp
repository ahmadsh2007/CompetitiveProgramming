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

const int N = 1e6;
vector<bool> sieve(int n){
    vector<bool> p(n+1,true);
    if(n>=0)p[0]=0;
    if(n>=1)p[1]=0;
    for(int i=2;i*i<=n;i++)if(p[i])for(int j=i*i;j<=n;j+=i)p[j]=0;
    return p;
}
vector<bool> primes(N);
vi spf(N + 1, 1);

void solve() {
    int n; cin >> n;
    vi a(n); cin >> a;

    bool ok = true;
    for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) ok = false;
    if (ok) {
        cout << "Bob\n";
        return;
    }


    vector<int> result;

    auto factorize = [](int x) -> vector<int> {
        vector<int> ret;
        if (x == 1) ret.push_back(x);
        while (x != 1) {
            ret.push_back(spf[x]);
            x /= spf[x];
        }

        reverse(all(ret));
        return ret;
    };

    vi ans;
    for (int i = 0; i < n; i++) {
        auto f = factorize(a[i]);
        ans.insert(ans.end(), f.begin(), f.end());
    }    

    bool nonD = 1;
    n = ans.size();
    for (int i = 1; i < n; i++) if (ans[i] < ans[i - 1]) nonD = 0;
    
    cout << (nonD ? "Bob" : "Alice") << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    primes = sieve(N);
    spf[0] = 0;
    for (int i = 2; i <= N; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= N; j += i) {
                if (spf[j] == 1) spf[j] = i;
            }
        }
    }

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    while (TTT--) solve();
    return 0;
}