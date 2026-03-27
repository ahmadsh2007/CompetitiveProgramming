/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) (int)(x).size()
// #define endl '\n'
// #define int long long
// #define str string // What a Python

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

void solve() {
    int count = 0;
    for (auto p : primes) {
        cout << p << endl;
        string judge; cin >> judge;
        if (judge == "yes") count++;
        if (p * p > 100) continue; 
        cout << p * p << endl;
        cin >> judge;
        if (judge == "yes") { count = 10; break;}
    }
    cout << (count >= 2 ? "composite" : "prime") << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    while (TTT--) solve();
    return 0;
}