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
    str a; int n; cin >> a >> n;
    vector<char> d(n); cin >> d;
    int size = (int) a.size();

    if (a == "0") { cout << d[0] << endl; return; }
    
    int val = stoll(a);

    str b;
    int idx = 0;
    for (int i = 0; i < size; ++i) {
        bool match = false;
        for (int j = 0; j < n; ++j) {
            if (d[j] == a[i]) {
                b += a[i];
                idx++;
                match = true;
                break; 
            }
        }
        if (!match) break;
    }

    if (idx == size) { cout << "0\n"; return; }

    int ans = LLONG_MAX;

    auto update = [&](string cur) {
        if (cur.empty()) return;
        ans = min(ans, abs(stoll(cur) - val));
    };

    for (int split = 0; split <= idx; ++split) {
        for (int i = n - 1; i >= 0; --i) {
            if (d[i] < a[split]) {
                string cur = a.substr(0, split) + d[i];
                while (cur.size() < size) cur += d.back();
                update(cur);
                break; 
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (d[i] > a[split]) {
                string cur = a.substr(0, split) + d[i];
                while (cur.size() < size) cur += d.front();
                update(cur);
                break;
            }
        }
    }

    if (size > 1) update(string(size - 1, d.back()));
    
    char first = (d[0] == '0' && n > 1) ? d[1] : d[0];
    if (first != '0' || n == 1) update(string(1, first) + string(size, d.front()));

    cout << ans << "\n";
}

const int TESTCASES = 1;
signed main() {
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