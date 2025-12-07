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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    sort(a.begin(), a.end());

    for(int i = 0; i < m; i++){
        int l = 0, r = n - 1;
        int mid = 0, ans = 0;
        int key = b[i];

        while(l <= r){
            mid = (l + r) / 2;
            if (a[mid] <= key){
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        cout << ans << ' ';
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
    // cin >> T;
    while (T--) solve();
    return 0;
}