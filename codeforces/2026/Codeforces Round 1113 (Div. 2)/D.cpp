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
    int n, q; cin >> n >> q;
    str s, t; cin >> s >> t;

    vector<vector<int>> prefix(n + 1, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        prefix[i + 1][0] = prefix[i][0] + (s[i] == '0' && t[i] == '1');
        prefix[i + 1][1] = prefix[i][1] + (s[i] == '1' && t[i] == '0');
    }

    while (q--) {
        int l, r; cin >> l >> r;

        int cnt1 = prefix[r][0] - prefix[l - 1][0];
        int cnt2 = prefix[r][1] - prefix[l - 1][1];
        int len = r - l + 1;

        if (cnt1 <= len / 2 and cnt2 <= len / 2) cout << "YES\n";
        else cout << "NO\n";
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