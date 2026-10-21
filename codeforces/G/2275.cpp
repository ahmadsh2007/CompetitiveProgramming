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

void solve () {
    int n, m, q; cin >> n >> m >> q;
    
    vector<array<int, 3>> e(m);
    int tot = 0;
    for (auto &[d, u, v] : e) {
        cin >> u >> v >> d;
        tot += d;
    }

    sort(all(e));

    vector<int> p(n + 1);
    for (int i = 0; i <= n; ++i) {
        p[i] = i;
    }
    auto find = [&](this auto &&self, int x) -> int {
        if (p[x] == x) {
            return x;
        }
        return p[x] = self(p[x]);
    };

    vector<int> w, pre{0};
    for (auto &[d, u, v] : e) {
        if (find(u) != find(v)) {
            p[find(u)] = find(v);
            w.push_back(d);
            pre.push_back(pre.back() + d);
        }
    }

    while (q--) {
        int x; cin >> x;
        int l = 1, r = (int) w.size();
        int mid, idx = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (w[mid - 1] < x * (n - mid)) {
                idx = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        int k = n - idx - 1;
        cout << tot - pre[idx] - x * k * (k + 1) / 2 << " \n"[q == 0];
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