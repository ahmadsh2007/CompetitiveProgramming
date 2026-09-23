#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../Utils/debug.h"
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 2e6;
vector<bool> isPrime(N + 100, 1);
vector<int> ithPrime;

void solve() {
    int q; cin >> q;

    while(q--){
        int x; cin >> x;
        cout << ithPrime[x - 1] << endl;
    }
}

const int TESTCASES = 0;
signed main() {
    #ifndef ONLINE_JUDGE
      freopen("../Utils/input.txt", "r", stdin);
      freopen("../Utils/output.txt", "w", stdout);
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    isPrime[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i] == 0) continue;
        int j = 2;
        while (j * i <= N) isPrime[i * j++] = 0;
    }


    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) ithPrime.push_back(i);
    }



    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}