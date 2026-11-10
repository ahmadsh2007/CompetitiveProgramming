/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 1e6 + 5;
vector<vector<int>> divs;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<int> freq(1e6 + 1);
    for (int i = 0; i < n; ++i) {
        for (const int& d : divs[a[i]]) {
            freq[d]++;
        }
    }

    for (int i = 1e6; i >= 1; --i) {
        if (freq[i] >= 2) {
            cout << i << endl;
            return;
        }
    }
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python
    divs.resize(N + 1);
    vector<int> cnt(N + 1);
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            cnt[j]++;
        }
    }
    for (int i = 1; i <= N; ++i) {
        divs[i].reserve(cnt[i]);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }

    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}