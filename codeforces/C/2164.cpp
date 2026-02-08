#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../Utils/debug.h"
#endif

template<class T>
istream& operator>>(istream& in, vector<T>& v)
{ for(auto& x:v) in>>x; return in; }
template<class T>
ostream& operator<<(ostream& out, vector<T>& v)
{ for(auto& x:v) out<<x<<' '; return out; }

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
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

void solve() {
    int n, m; cin >> n >> m;
    multiset<int> a;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
        mx = max(mx, x);
    }

    vi b(m), c(m); cin >> b >> c;
    vector<pair<int, int>> bc;
    vector<pair<int, int>> last;
    for (int i = 0; i < m; i++) {
        if (c[i] != 0) {
            bc.push_back({b[i], c[i]});
        }
        else
        {
            last.push_back({b[i], 0});
        }
    }

    sort(all(bc), [](const pair<int,int> &p1, const pair<int,int> &p2) {
        if (p1.first != p2.first)
            return p1.first < p2.first;
        return p1.second > p2.second;
    });
    sort(all(last), [](const pair<int,int> &p1, const pair<int,int> &p2) {
        return p1.first < p2.first;
    });

    bool DEBUGMODE = 0;
    if (DEBUGMODE) {
        for (auto x : bc)   cout << x.first << ' ' << x.second << endl;
        for (auto x : last) cout << x.first << ' ' << x.second << endl;
        return;
    }

    int ans = 0;
    for (int i = 0; i < bc.size(); i++) {
        auto x = a.lower_bound(bc[i].first);
        if (x != a.end()) {
            ans++;
            a.insert(max(*x, bc[i].second));
            a.erase(x);
        }
    }

    for (int i = 0; i < last.size(); i++) {
        auto x = a.lower_bound(last[i].first);
        if (x != a.end()) {
            ans++;
            a.erase(x);
        }
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

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