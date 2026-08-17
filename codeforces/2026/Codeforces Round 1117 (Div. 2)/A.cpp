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
    set<char> firstLetters;
    for (int i = 0; i < n; ++i) {
        str s; cin >> s;
        firstLetters.insert(toupper(s[0]));
    }

    vector<str> words(m); cin >> words;
    for (int i = 0; i < m; ++i) {
        for (str & w : words) {
            if (w.empty()) continue;
            bool ok = 1;
            for (const char & c : w) {
                if (firstLetters.find(c) == firstLetters.end()) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                firstLetters.insert(w[0]);
                w = "";
            }
        }
    }

    for (const str & w : words) {
        if (!w.empty()) {
            return void(cout << "NO\n");
        }
    }

    cout << "YES\n";
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}