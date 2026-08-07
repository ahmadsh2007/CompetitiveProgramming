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
    int n, m; cin >> n >> m;
    vector<int> v(n); cin >> v;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){ 
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) sort(rall(a[i]));

    vector<int> prefixMin(n);
    prefixMin[0] = v[0];
    for (int i = 1; i < n; ++i) prefixMin[i] = min(prefixMin[i - 1], v[i]);

    int ans = m;
    vector<int> pieces;
    for (int i = n - 1; i >= 0; --i) {
        pieces.insert(pieces.end(), all(a[i]));
        
        sort(rall(pieces));
        
        if (pieces.size() > m) pieces.resize(m);
        
        int cur = 0;
        int cnt = 0;
        for (int j = 0; j < (int) pieces.size(); ++j) {
            cur += pieces[j];
            cnt++;
            if (cur >= prefixMin[i]) {
                ans = min(ans, cnt);
                break;
            }
        }
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