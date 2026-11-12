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

const int X = 500000;
struct Node {
    int a, b, d;
};

void solve() {
    // ∑((x + a[i]) mod b[i]) = ...
    // ∑((x + a[i]) - b[i] * ((x + a[i]) / b[i])) = ...
    // N * x + ∑a[i] - ∑(b[i] * ((x + a[i]) / b[i]))
    //                  \_________ F(x) _________/

    int n; cin >> n;
    vector<Node> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].a >> v[i].b;
        v[i].d = v[i].b - v[i].a;
    }
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i].a;
    }

    sort(all(v), [](const Node& a, const Node& b) {
        if (a.b != b.b) return a.b < b.b;
        return a.d < b.d;
    });
    for (const auto &[a, b, d] : v) {
        cerr << a << ' ' << b << ' ' << d << endl;
    }

    vector<vector<array<int, 2>>> byB(X + 1);
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n and v[j].b == v[i].b and v[j].d == v[i].d) j++;
        byB[v[i].b].push_back({v[i].d, v[i].b * (j - i)});
        i = j;
    }
    // floor((x + a) / b) increases by 1 at x = d, d + b, d + 2b, ...
    // each increase adds b to F
    vector<int> jump(X + 1);
    for (int b = 1; b <= X; ++b) {
        if (byB[b].empty()) {
            continue;
        }

        for (int base = 0; base <= X; base += b) {
            for (auto &[d, w] : byB[b]) {
                int t = base + d;
                if (t > X) {
                    break;
                }
                jump[t] += w;
            }
        }
    }
    // Prefix sum: F[x] = ∑ b[i] * floor((x + a[i]) / b[i])
    vector<int> F(X + 1);
    int cur = 0;
    for (int x = 0; x <= X; ++x) {
        cur += jump[x];
        F[x] = cur;
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << n * x + sum - F[x] << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}