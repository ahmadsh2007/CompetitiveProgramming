/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define str string
#define endl '\n'

void first() {
    int n; cin >> n;
    str s; cin >> s;

    int x = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1') {
            x = i + 2;
            break;
        }
    }

    vector<pair<int, int>> e;
    if (~x) {
        for (int i = 2; i <= n; ++i) {
            e.push_back({(s[i - 2] == '1' ? 1 : x), i});
        }
    }
    else {
        for (int i = 2; i <= n; ++i) {
            e.push_back({1, i});
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
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colors(n + 1, -1);

    bool hasOne = true;
    auto dfs = [&](this auto&& self, int u, int p, int color) -> void {
        if (~colors[u]) {
            if (colors[u] != color) {
                hasOne = false;
                return;
            }
        }
        colors[u] = color;
        for (auto &v : adj[u]) {
            if (v != p) {
                self(v, u, color ^ 1);
            }
        }
    };
    dfs(1, 0, 0);

    if (hasOne) {
        string ans;
        for (int i = 2; i <= n; ++i) {
            ans += (colors[i] + '0');
        }

        cout << ans << endl;
    }
    else {
        cout << string(n - 1, '0') << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    str op; cin >> op;
    int t; cin >> t;
    if (op == "first") {
        while (t--) {
            first();
        }
    }
    else {
        while (t--) {
            second();
        }
    }
}