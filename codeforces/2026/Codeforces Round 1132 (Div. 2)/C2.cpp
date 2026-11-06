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
#define endl '\n'
#define int long long
#define str string // What a Python

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

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

void solve() {
    int a, b; cin >> a >> b;

    if (a == b) {
        return void(cout << 0 << endl);
    }

    vector<int> ans;
    if (gcd(a, b) == 1) {
        return void(cout << 1 << endl << b - a << endl);
    }
    
    for (int i = a + 1; i < b; ++i) {
        if (gcd(a, i) == 1 and gcd(i, b) == 1) {
            return void(cout << 2 << endl << i - a << ' ' << b - i << endl);
        }
    }

    for (int i = a + 1; i < b; ++i) {
        for (int j = i + 1; j < b; ++j) {
            if (gcd(a, i) == 1 and gcd(i, j) == 1 and gcd(j, b) == 1) {
                return void(cout << 3 << endl << i - a << ' ' << j - i << ' ' << b - j << endl);
            }
        }
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}