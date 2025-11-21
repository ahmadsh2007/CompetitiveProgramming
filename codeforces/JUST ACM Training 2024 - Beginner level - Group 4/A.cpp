#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();


void solve() {
    int n; cin >> n;

    vector<int> a(n), result;
    vector<bool> s(1111, 0);

    for (auto &x : a) cin >> x;

    for (int i = n - 1; i >= 0; i--){
        if(!s[a[i]]) {
            s[a[i]] = true;
            result.push_back(a[i]);
        }
    }

    reverse(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}