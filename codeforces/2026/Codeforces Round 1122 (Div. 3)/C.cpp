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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve() {
    int n; cin >> n;
    str s; cin >> s;
    int firstOne = -1, firstZero = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1' and firstOne == -1) firstOne = i;
        if (s[i] == '0' and firstZero == -1) firstZero = i;
    }
    
    vector<int> prefix(n + 1), suffix(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (s[i] == '1');
    }
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + (s[i] == '0');
    }
    
    int ans = LLONG_MAX;
    for (int i = 0; i <= n; ++i) {
        if (prefix[i] > 0 and firstOne < firstZero) continue;
        if (suffix[i] > 0 and (firstOne == -1 or i < firstOne)) continue;
        
        ans = min(ans, prefix[i] + suffix[i]);
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