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

const int N = 50001;
bitset<N> pre[N];
bitset<N> g[N];

static const int PRECOMPUTE = [](){
    const int M = N - 1;
    vector<bool> sqfree(M + 1, true);
    for (int p = 2; p * p <= M; p++)
        for (int x = p * p; x <= M; x += p * p)
            sqfree[x] = false;

    vector<vector<int>> divs(M + 1);
    for (int d = 1; d <= M; d++)
        if (sqfree[d])
            for (int x = d; x <= M; x += d)
                divs[x].push_back(d);

    bitset<N> cur;
    for (int i = 1; i <= M; i++) {
        cur.reset();
        for (int d : divs[i]) cur ^= g[d];
        cur[1] = 1;

        pre[i] = pre[i - 1] ^ cur;

        bitset<N> sh = cur << 1;
        for (int d : divs[i]) g[d] ^= sh;
    }

    return 0;
}();

void solve() {
    int n, m; cin >> n >> m;
    cout << pre[m][n] << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}