#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using ull = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    str e, d; cin >> e >> d;
    map<char, int> freqE;
    for (int i = 0; i < e.size(); i++) freqE[e[i]]++;

    map<char, int> freqD;
    for (int i = 0; i < d.size(); i++) freqD[d[i]]++;

    map<char, int> preAdv;
    for (int i = 0; i < d.size(); i++) preAdv[e[i]]++;

    if (preAdv == freqD) { cout << "YES" << endl; return; }

    for (int i = d.size(); i < e.size(); i++) {
        preAdv[e[i]]++;
        preAdv[e[i - d.size()]]--;

        if (preAdv[e[i - d.size()]] == 0) preAdv.erase(e[i - d.size()]);
        if (preAdv == freqD) { cout << "YES" << endl; return; }
    }

    cout << "NO" << endl;
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}