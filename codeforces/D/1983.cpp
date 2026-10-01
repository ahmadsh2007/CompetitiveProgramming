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
    vector<pair<int, int>> a(n), b(n);
    map<int, int> freq[2];
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[i] = {x, i};
        freq[0][x]++;
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b[i] = {x, i};
        freq[1][x]++;
    }

    if (freq[0] != freq[1]) {
        return void(cout << "NO\n");
    }

    sort(all(a));
    sort(all(b));

    auto getParity = [&](const vector<pair<int, int>> & v) {
        vector<bool> vis(n);
        int cycles = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                cycles++;
                int curr = i;
                while (!vis[curr]) {
                    vis[curr] = true;
                    curr = v[curr].second;
                }
            }
        }
        return (n - cycles) % 2;
    };

    if (getParity(a) == getParity(b)) cout << "YES\n";
    else cout << "NO\n";
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}