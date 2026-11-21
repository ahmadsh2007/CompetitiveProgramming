/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

template<class T>istream& operator>>(istream& in, vector<T>& v){for(auto& x:v) in>>x;return in;}
template<class T>ostream& operator<<(ostream& out, vector<T>& v){for(auto& x:v) out<<x<<' ';return out;}

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const long long INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    int x, y, m; cin >> x >> y >> m;
    str s; cin >> s;
    
    int ans = x + y;
    for (int i = 0; i < m; ++i) {
        str cur = s.substr(0, i + 1);
        int xx = x;
        int yy = y;
        for (const char& c : cur) {
            if (c == '-') {
                if (yy == 1 and xx) {
                    xx--;
                }
                else if (yy) {
                    yy--;
                    xx++;
                }
                else if (xx) {
                    xx--;
                }
            }
            else {
                if (yy) {
                    yy++;
                }
                else if (xx) {
                    xx--;
                    yy++;
                }
            }
        }
        ans = max(ans, xx + yy);
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