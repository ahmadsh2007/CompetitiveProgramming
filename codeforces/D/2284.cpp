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

void first() {
    int n; cin >> n;
    str s; cin >> s;
    vector<pair<int, int>> e;
    int x = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1') {
            x = i + 2;
            break;
        }
    }

    if (~x) {
        for (int v = 2; v <= n; ++v) {
            e.push_back({(s[v - 2] == '1' ? 1 : x), v});
        }
    }
    else {
        for (int v = 2; v <= n; ++v) {
            e.push_back({1, v});
        }
        e.push_back({2, 3});
    }

    cout << (int) e.size() << endl;
    for (auto &[u, v] : e) {
        cout << u << ' ' << v << endl;
    }
}
void second() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c(n + 1, -1);
    c[1] = 0;
    queue<int> q;
    q.push(1);
    bool flag = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int &v : g[u]) {
            if (c[v] == -1) {
                c[v] = c[u] ^ 1;
                q.push(v);
            }
            else if (c[v] == c[u]) {
                flag = false;
            }
        }
    }

    str ans;
    for (int v = 2; v <= n; ++v) {
        ans += flag ? (char) ('0' + c[v]) : '0';
    }
    cout << ans << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    str op; cin >> op;
    int t; cin >> t;
    if (op == "first") {
        for (int i = 0; i < t; ++i) {
            first();
        }
    }
    else {
        for (int i = 0; i < t; ++i) {
            second();
        }
    }
    return 0;
}