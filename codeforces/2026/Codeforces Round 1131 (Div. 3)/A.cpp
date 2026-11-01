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
    int n, m; cin >> n >> m;
    map<char, int> freq[2];
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        freq[0][x]++;
    }
    for (int i = 0; i < m; ++i) {
        char x; cin >> x;
        freq[1][x]++;
    }

    for (auto &[x, cnt] : freq[1]) {
        freq[0][x] -= cnt;
    }

    for (auto &[x, cnt] : freq[0]) {
        if (x == 's' or x == 'i' or x == 'x') {
            if (cnt != 1) {
                return void(cout << "NO" << endl);
            }
        }
        else {
            if (cnt != 0) {
                return void(cout << "NO" << endl);
            }
        }
    }

    cout << "YES" << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}