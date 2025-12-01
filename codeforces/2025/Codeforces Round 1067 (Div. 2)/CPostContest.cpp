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
    // * POST CONTEST
    // Solve copied from codeforces tutorials, but don't worry I understand it (hopefully)

    int n, k; cin >> n >> k;
    vector<i64> a(n), b(n);
    for(auto &x : a)cin >> x;
    for(auto &x : b)cin >> x;

    k %= 2; // k &= 1;

    vector<int> L(n);
    for(int i = 0; i < n; i++){
        L[i] = (i && L[i - 1] > 0 ? L[i - 1] : 0ll) + a[i]; 
    }   

    vector<int> R(n);
    for(int i = n - 1; i >= 0; i--){
        R[i] = (i + 1 < n && R[i + 1] > 0 ? R[i + 1] : 0ll) + a[i];
    }

    if(k == 0){
        int ans = *max_element(L.begin(),L.end());
        cout << ans << "\n";
    }
    else{
        int ans = LONG_MIN;
        for(int i = 0; i < n; i++){
            ans = max(ans, L[i] + R[i] - a[i] + b[i]);
        }
        cout << ans << "\n";
    }
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