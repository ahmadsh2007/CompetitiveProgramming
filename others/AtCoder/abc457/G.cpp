/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    // Apple j is reachable from apple i iff
    // abs(X[i] - X[j]) <= T[j] - T[i]
    // same as T[i] - T[j] <= X[i] - X[j] <= T[j] - T[i]
    // so we get two formulas,
    // 1. T[i] - X[i] <= T[j] - X[j]
    // 2. T[i] + X[i] <= T[j] + X[j]
    // U[i] = T[i] + X[i]
    // V[i] = T[i] - X[i]

    vector<pair<int, int>> reachable(n);
    for (int i = 0; i < n; ++i) {
        reachable[i].first = a[i].first + a[i].second;
        reachable[i].second= a[i].first - a[i].second;
    }

    sort(all(reachable), [](const pair<int, int>& a, const pair<int, int>& b){
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    vector<int> g;
    for (const auto &[t, x] : reachable) {
        auto it = lower_bound(all(g), x);
        if (it == g.end()) {
            g.push_back(x);
        }
        else {
            *it = x;
        }
    }

    cout << (int) g.size() << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}