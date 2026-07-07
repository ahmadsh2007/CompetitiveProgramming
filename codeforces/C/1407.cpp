/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define str string // What a Python

void solve() {
    int n; cin >> n;
    int ans[n + 1];
    stack<int> pos;
    unordered_set<int> val;
    for (int i = 1; i <= n; ++i) {
        pos.push(i);
        val.insert(i);
    }
    while ((int) pos.size() > 1) {
        int x = pos.top();
        pos.pop();
        int y = pos.top();
        pos.pop();
        printf("? %d %d\n", x, y);
        int a; cin >> a;
        printf("? %d %d\n", y, x);
        int b; cin >> b;

        val.erase(max(a, b));

        if (a > b) {
            ans[x] = a;
            pos.push(y);
        }
        else {
            ans[y] = b;
            pos.push(x);
        }
    }

    ans[pos.top()] = *val.begin();

    cout << "! ";
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    solve();
    return 0;
}