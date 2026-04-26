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

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int d;
int check(const vector<int>& left, const vector<int>& right) {
    int ans = 0;
    int leftIndex = 0, rightIndex = 0;
    while (true) {
        if (leftIndex >= left.size()) break;
        if (rightIndex>=right.size()) break;
        int i = left[leftIndex];
        int j = right[rightIndex];
        
        if (j - i == d) {
            ans++;
            leftIndex++; 
            rightIndex++;
        }
        else if (j - i < d) rightIndex++;
        else leftIndex++;
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x < n) a[x].push_back(i);
    }

    int ans = 0;
    for (int x = 1; x * x <= n; x++) {
        if (a[x].empty()) continue;

        for (int y = x; x * y < n; y++) {
            if (a[y].empty()) continue;

            d = x * y;
            ans += check(a[x], a[y]);
            if (x != y) ans += check(a[y], a[x]);
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