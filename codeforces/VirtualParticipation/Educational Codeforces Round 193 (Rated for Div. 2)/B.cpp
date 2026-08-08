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
    vector<int> a(n); cin >> a;

    vector<int> b;
    vector<int> s;
    b.push_back(a[0]);
    s.push_back(1);
    
    for (int i = 1; i < n; ++i) {
        if (a[i] == b.back()) {
            s.back()++;
        }
        else {
            b.push_back(a[i]);
            s.push_back(1);
        }
    }

    int m = (int) b.size();
    int plus2 = 0;
    int plus1 = 0;
    for (int i = 0; i < m - 1; ++i) {
        if (s[i] >= 2 and s[i + 1] >= 2) {
            plus2 = 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        if (s[i] >= 2) {
            if (i + 1 < m) {
                if (i + 2 >= m or b[i + 2] != b[i]) {
                    plus1 = 1;
                }
            }
            if (i - 1 >= 0) {
                if (i - 2 < 0 or b[i - 2] != b[i]) {
                    plus1 = 1;
                }
            }
        }
    }

    if (plus2) {
        cout << m + 2 << endl;
    }
    else if (plus1) {
        cout << m + 1 << endl;
    }
    else {
        cout << m << endl;
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