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

int gcd(int a, int b){
    while (b != 0){
        int temp = a;
        a = b;
        b = temp % b;
    }

    return a;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    bool ok = 0;
    for(int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if(gcd(a[i], a[j]) <= 2) ok = 1;

    cout << (ok ? "YES\n" : "NO\n");
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}