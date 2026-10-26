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

void solve() {
    int n; cin >> n;
    str grid[2]; cin >> grid[0] >> grid[1];

    int cnt[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        if (grid[0][i] == 'f') {
            cnt[0]++;
        }
        if (grid[1][i] == 'f') {
            cnt[1]++;
        }
    }
    if (cnt[0] < cnt[1]) {
        swap(cnt[0], cnt[1]);
        swap(grid[0],  grid[1]);
    }

    int diff = cnt[0] - cnt[1];
    int tot = 0;
    for (int i = 0; i + 1 < n;){
        if (grid[0][i] == 'f' and grid[0][i + 1] == 'f') {
            tot++;
            i += 2;
        }
        else {
            i++;
        }
    }

    int ans = diff - 2 * tot;
    if (diff % 2 > ans) {
        ans = diff % 2;
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