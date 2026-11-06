/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define str string
#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

map<int, int> center;
map<vector<set<int>>, str> ans;

void first() {
    int n; cin >> n;
    str s; cin >> s;

    if (center.count(n)) {
        center[n] = 1;
    }
    else {
        center[n]++;
    }

    int centerNode = center[n];
    vector<set<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i == centerNode) continue;
        adj[centerNode].insert(i);
    }
    int found = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (i == centerNode) {
            found = 1;
            continue;
        }

        adj[(centerNode + i) % n + 1].insert((centerNode + i + 1) % n + 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (const int & x : adj[i]) {
            cout << i << ' ' << x << endl;
        }
    }
    
    ans[adj] = s;
}
void second() {
    int n, m; cin >> n >> m;
    
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    str op; cin >> op;
    if (op == "first") {
        int t; cin >> t;
        while (t--) {
            first();
        }
    }
    else {
        int t; cin >> t;
        while (t--) {
            second();
        }
    }
    return 0;
}