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
    int n; cin >> n;
    str s; cin >> s;
    str t; cin >> t;

    vector<int> eve1, odd1;
    vector<int> eve2, odd2;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i % 2 == 0) eve1.push_back(i / 2);
            else odd1.push_back(i / 2);
        }
        if (t[i] == '1') {
            if (i % 2 == 0) eve2.push_back(i / 2);
            else odd2.push_back(i / 2);
        }
    }

    if (eve1.size() != eve2.size() or odd1.size() != odd2.size()) return void(cout << "-1\n");

    int ans = 0;
    for (int i = 0; i < eve1.size(); ++i) ans += abs(eve1[i] - eve2[i]);
    for (int i = 0; i < odd1.size(); ++i) ans += abs(odd1[i] - odd2[i]);

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