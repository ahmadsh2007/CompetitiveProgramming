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

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int solve(int n, int k, int i, vector<int> & a, vector<int> & prefix) {
    auto query = [&](int l, int r) -> int {
        if (r < l or r < 0) return 0;
        if (r < i) {
            return prefix[r] - (l == 0 ? 0 : prefix[l - 1]);
        }
        else if (l > i) {
            return prefix[r + 1] - prefix[l];
        }
        return prefix[r + 1] - (l == 0 ? 0 : prefix[l - 1]) - a[i];
    };

    auto ind = [&](int target) -> int {
        int l = 0, r = n - 1;
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (mid == 0 or (query(0, mid - 1) < target)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return r;
    };

    int lastGoodPos = ind(a[i]);
    vector<int> bad;
    int pos = -1;

    while (true) {
        int value = query(0, pos) + a[i];

        int badPos = ind(value * 2 + 1 - a[i]);

        if (badPos >= n - 1) break;

        value = query(0, badPos - 1) + a[i];

        bool isBad = query(badPos, badPos) > value;

        if (isBad) { 
            bad.push_back(badPos + 1);
        }
        pos = badPos;
    }
    
    if (k == 0) {
        if (bad.empty()) return lastGoodPos + 1;
        return 0;
    }
    else if (bad.size() > k) {
        return n - bad[(int) bad.size() - k];
    }
    else if (bad.size() < k) {
        return n;
    }
    else {
        return min(n, (lastGoodPos + 1) + (n - bad[0]));
    }
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    for (int i = 0; i < n; ++i) {
        cout << solve(n, k, i, a, prefix) << " \n"[i == n - 1];
    }
}

void debug();

const int TESTCASES = 1;
const int DEBUGGING = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    if (DEBUGGING) {
        debug();
        return 0;
    }
    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}

void debug() {
    int n = 7;
    vector<int> a{0, 1, 3, 3, 17, 39, 3, 12};
    for (int j = 1; j <= n; ++j) {
        cerr << "solving for index: " << j << ", number: " << a[j] << endl;
        vector<int> p, v, d;
        int tot = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == j) {
                continue;
            }
            p.push_back(tot);
            v.push_back(a[i]);
            d.push_back(a[i] - tot);
            tot += a[i];
        }
        p.push_back(tot);
        d.push_back(a.back() - tot);

        for (int i = 0; i < n; ++i) {
            cerr << p[i] << "\t\n"[i == n - 1];
        }
        for (int i = 0; i < n; ++i) {
            cerr << v[i] << "\t\n"[i == n - 1];
        }
        for (int i = 0; i < n; ++i) {
            cerr << d[i] << "\t\n"[i == n - 1];
        }
        cerr << endl;
    }
}