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

int mn(vector<int> &x){
    int pos = x.size() / 2;
    int ans = 0;
    for(int i = 0; i < x.size(); i++)
        ans += abs(x[i] - x[pos]) - abs(pos - i);

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if (c == 'a') a.push_back(i);
        else b.push_back(i);
    }

    cout << min(mn(a), mn(b)) << endl;
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