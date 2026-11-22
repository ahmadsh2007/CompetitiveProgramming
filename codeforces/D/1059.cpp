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
    int n; cin >> n;
    vector<array<int, 2>> p(n);
    bool no[2] = {false, false};
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0] >> p[i][1];
        if (p[i][1] > 0) {
            no[1] = true;
        }
        if (p[i][1] < 0) {
            no[0] = true;
        }
        p[i][1] = abs(p[i][1]);
    }
    
    if (no[0] and no[1]) {
        return void(cout << -1 << endl);
    }

    auto f = [&](double c) -> double {
        double R = 0;
        for (auto &[x, y] : p) {
            double dx = abs(x - c);
            double dy = y;
            R = max(R, dx * dx / (2 * dy) + dy / 2);
        }
        
        return R;
    };

    double l = -1e7, r = 1e7;
    double m1, m2, ans;
    for (int i = 0; i < 100; ++i) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        if (f(m1) < f(m2)) r = m2;
        else l = m1;
    }

    cout << fixed << setprecision(15) << f((l + r) / 2) << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}