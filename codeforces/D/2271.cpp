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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> l(n), r(n), prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        prefix[i + 1] = prefix[i] + r[i] - l[i] + 1;
    }

    auto getInfected = [&](int s) -> int {
        int e = s + m - 1;

        int i = lower_bound(all(r), s) - r.begin();
        int j = upper_bound(all(l), e) - l.begin() - 1;

        if (i > j) return 0;

        int res = prefix[j + 1] - prefix[i];
        res -= max(0ll, s - l[i]);
        res -= max(0ll, r[j] - e);

        return res;
    };

    int mx = 0, left = 0, rght = 1e18;
    for (int i = 0; i < n; ++i) {
        int val = getInfected(l[i]);
        if (val > mx) {
            mx = val;
            left = l[i];
        }
    }

    if (k > mx) {
        return void(cout << -1 << endl);
    }

    int ans = 0;
    while (left <= rght) {
        int mid = left + (rght - left) / 2;
        if (getInfected(mid) < k) {
            rght = mid - 1;
        }
        else {
            ans = mid;
            left = mid + 1;
        }
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}