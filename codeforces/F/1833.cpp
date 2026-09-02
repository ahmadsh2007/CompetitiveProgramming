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

long long modpow(long long a,long long e,long long mod){long long r=1;while(e){if(e&1)r=r*a%mod;a=a*a%mod;e>>=1;}return r;}

void solve() {
    int n, m; cin >> n >> m;
    map<int, int> freq;
    set<int> nums;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        nums.insert(x);
        freq[x]++;
    }
    if ((int) nums.size() < m) {
        return void(cout << 0 << endl);
    }

    vector<int> a;
    a.reserve((int) nums.size());
    for (const int & num : nums) {
        a.push_back(num);
    }

    int ans = 0;
    vector<int> prefix((int) a.size());
    prefix[0] = freq[a[0]];
    for (int i = 1; i < (int) a.size(); ++i) {
        prefix[i] = (1ll * prefix[i - 1] * freq[a[i]]) % MOD;
    }
    
    for (int i = 0; i <= (int) a.size() - m; ++i) {
        if (a[i + m - 1] - a[i] != m - 1) continue;
        
        int cur = prefix[i + m - 1];
        if (i > 0) {
            cur = (cur * modpow(prefix[i - 1], MOD - 2, MOD)) % MOD;
        }
        ans = (ans + cur) % MOD;
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