/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// Vector input/output operators
// I wish I could just do `v = list(map(int, input().split()))` instead of this boilerplate
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto& x:v) in>>x;
    return in;
}
// I wish I could just do `print(*v)` instead of this boilerplate
template<class T>
ostream& operator<<(ostream& out, vector<T>& v){
    for(auto& x:v) out<<x<<' ';
    return out;
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct Desk {
    int id;
    int from;
    int to;
};
vector<int> a;
vector<Desk> ans;

void solve(int n, int from, int to, int aux) {
    if (n <= 0) return;
    if (a[n] == 0) {
        solve(n - 1, from, aux, to);
        ans.push_back({n, from, to});
        solve(n - 1, aux, to, from);
    }
    else {
        solve(n - 1 - a[n], from, aux, to);
        ans.push_back({n, from, to});
        solve(n - 1 - a[n], aux, from, to);
        solve(n - 1, from, to, aux);
    }
}

void solve() {
    int n; cin >> n;
    a.assign(n + 1, 0ll);
    ans.clear();
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] > i - 1) flag = true;
    }
    if (flag) {
        return void(cout << "NO\n" << endl);
    }

    solve(n, 1, 3, 2);

    cout << "YES\n" << (int) ans.size() << endl;
    for (const Desk & d : ans) {
        cout << d.id << ' ' << d.from << ' ' << d.to << endl;
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}