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
    int t, m; cin >> t >> m;
    vector<int> mem(m);
    int nextId = 1;

    while (t--) {
        str op; cin >> op;
        if (op == "alloc") {
            int n; cin >> n;
            bool placed = false;
            for (int i = 0; i + n <= m and !placed; i++) {
                bool freeRun = true;
                for (int j = i; j < i + n; j++)
                    if (mem[j] != 0) {
                        freeRun = false;
                        break;
                    }
                if (freeRun) {
                    for (int j = i; j < i + n; j++) mem[j] = nextId;
                    cout << nextId++ << endl;
                    placed = true;
                }
            }
            if (!placed) cout << "NULL\n";
        }
        else if (op == "erase") {
            int x; cin >> x;
            bool found = false;
            if (x > 0) {
                for (int j = 0; j < m; j++)
                    if (mem[j] == x) {
                        mem[j] = 0;
                        found = true;
                    }
            }
            if (!found) cout << "ILLEGAL_ERASE_ARGUMENT\n";
        }
        else {
            vector<int> packed;
            for (int c : mem) if (c != 0) packed.push_back(c);
            packed.resize(m);
            mem = packed;
        }
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