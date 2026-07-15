/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int MOD = 32768;
vector<int> moves(MOD, -1);
int precompute(int x, int depth) {
    if (x == 0) return 0;
    if (depth >= 15) return 15;

    if (moves[x] != -1 && moves[x] <= depth) return moves[x];

    int best = min(precompute((x + 1) % MOD, depth + 1) + 1, 
                   precompute((2 * x) % MOD, depth + 1) + 1);

    if (moves[x] == -1 || best < moves[x]) moves[x] = best;
    return moves[x];
}

void solve() {
    int n; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cout << moves[x] << " \n"[i == n - 1];
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    moves[0] = 0;
    for (int i = 1; i < MOD; ++i) precompute(i, 0);
    solve();
    return 0;
}