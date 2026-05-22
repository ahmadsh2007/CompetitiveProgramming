#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int long long
#define endl '\n'
#define str string

static const int IOSPEED = []() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int binpow(int a, int b) {
    int res = 1;
    while (b > 0)  {
        if ((b & 1)) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int getMEX(const vector<int> & a) {
    int len = a.size();
    vector<char> s(a.size() + 4);
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] >= 0 && a[i] <= len + 2) s[a[i]] = 1;
    }
    int m = 0;
    while (s[m]) m++;
    return m;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<map<int, int>> c(13);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < 10; ++j) {
            int d = binpow(10, j);
            // cout << d << endl;
            c[j][(a[i] * d) % k]++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int d = 0;
        int temp = a[i];
        while (temp) d++, temp /= 10;
        // cout << "check: " << d << endl;

        int searchFor = (k - a[i] % k) % k;
        // cout << "check: " << searchFor << endl;
        ans += c[d][searchFor];
    }

    // cout << "START:" << endl;
    // for (int i = 0; i < 18; ++i) {
    //     for (auto &x : c[i]) cout << x.first << ' ' << x.second << endl;;
    // }
    // cout << "END:" << endl << endl;

    cout << ans << endl;
} 

bool testcases = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1;
    if (testcases) cin >> t;
    while(t--) solve();
    return 0;
}