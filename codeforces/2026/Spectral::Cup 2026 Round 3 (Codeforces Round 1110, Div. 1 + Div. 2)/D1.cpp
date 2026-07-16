/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 1005, M = 505520;
int operations1[M], operations2[M], operations3[M];
int a1[N], a2[N];
int ind[M];

void solve() {
    int n, mm; cin >> n >> mm;
    int m = 0;
    for (int i = 0; i <= n; ++i) a1[i] = a2[i] = 0;

    for (int i = 0; i < mm; ++i) {
        int x, xx, xxx; cin >> x >> xx >> xxx;
        if (xx == xxx) {
            if (x == 1){
                if (a2[xx] == -1) return void(cout << "NO\n");
                a2[xx] = 1;
            } else {
                if (a2[xx] == 1) return void(cout << "NO\n");
                a2[xx] = -1;
            }
        }
        else {
            operations1[m] = x;
            operations2[m] = xx;
            operations3[m] = xxx;
            m++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a2[i] == -1) a1[i]--;
    }

    for (int i = 0; i < m; ++i) {
        int idx1 = operations2[i], idx2 = operations3[i];
        if (operations1[i] == 1) {
            if (a2[idx1] == -1 and a2[idx2] == -1) return void(cout << "NO\n");
            if (a2[idx1] == 1) ind[i] = idx1;
            else if (a2[idx2] == 1) ind[i] = idx2;
            else ind[i] = idx2;
        } else {
            if (a2[idx1] == 1 and a2[idx2] == 1) return void(cout << "NO\n");
            if (a2[idx1] == -1) ind[i] = idx1;
            else if (a2[idx2] == -1) ind[i] = idx2;
            else ind[i] = idx2;
        }
    }

    bool flag = 1;
    int idx1, idx2, val;
    int nn = n;
    for (int j = 0; j <= nn; ++j) {
        bool changesHappened = 0;
        for (int i = 0; i < m; ++i) {
            idx1 = operations2[i];
            idx2 = operations3[i];
            if (idx1 == idx2) continue;
            val = a1[idx1] + a1[idx2];
            if (operations1[i] == 1) {
                if (val < 0) {
                    a1[ind[i]] += (0 - val);
                    changesHappened = 1;
                }
            } else {
                if (val >= 0) {
                    a1[ind[i]] += (-1 - val);
                    changesHappened = 1;
                }
            }
        }

        if (!changesHappened) break;
        if (j == nn) flag = 0;
    }
    if (!flag) return void(cout << "NO\n");
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) cout << a1[i] << " \n"[i == n];
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}