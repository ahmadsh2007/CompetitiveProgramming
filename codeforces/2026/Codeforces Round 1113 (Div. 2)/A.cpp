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
    str s; cin >> s;
    int n = (int) s.size();
    str ans = "";

    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            str temp = s.substr(0, i) + s.substr(i + 1);

            str cur;
            for (int j = 0; j < (int) temp.size(); ++j) {
                if (temp[j] == '1') {
                    str temp2 = temp.substr(0, j) + temp.substr(j + 1);
                    if (cur == "" or temp2 < cur) {
                        cur = temp2;
                    }
                }
            }

            if (ans == "" or cur > ans) {
                ans = cur;
            }
        }
    }

    cout << ans << "\n";
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}