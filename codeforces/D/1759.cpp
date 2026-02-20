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

int p2[19];
int p5[19];

void solve() {
    int n, m; cin >> n >> m;
    int twos = 0, five = 0;
    int nn = n;
    while (nn % 2 == 0) nn /= 2, twos++;
    while (nn % 5 == 0) nn /= 5, five++;

    for (int dig = 18; dig >= 0; dig--) {
        int extra2 = max(0ll, dig - twos);
		int extra5 = max(0ll, dig - five);

        int need = p2[extra2] * p5[extra5];
        if (need <= m) {
            int largest = m - m % need;
            cout << n * largest << endl;
            return;
        }
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    p2[0] = 1;
    p5[0] = 1;
    for (int i = 1; i <= 18; i++) {
        p2[i] = 2 * p2[i - 1];
        p5[i] = 5 * p5[i - 1];
    }


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