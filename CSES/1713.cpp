/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define str string // What a Python
#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 1e6 + 5;
vector<int> divisors(N + 1);
static const int PRECOMPUTE = []() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divisors[j]++;
        }
    }
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 0; i < n; ++i) {
        cout << divisors[a[i]] << endl;
    }
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}