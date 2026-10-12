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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fill(vector<int> & ans, int n, int k, int org, int rep, int cnt, int idx, int val) {
    if (idx >= n || rep > org) return;
    int s = org - rep + 1;
    cnt = org / s;
    for (int i = 0; i < cnt and idx + s <= n; ++i) {
        for (int j = 0; j < s; ++j) ans[idx++] = val;
        val++;
    }
    fill(ans, n, k, org, rep + 1, cnt, idx, val);

}

void solve() {
    int n; cin >> n;

    int l = 1, r = 600;
    int k = 600;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int cap = 0;
        for (int i = 1; i <= mid; ++i) cap += i * (mid / i);

        if (cap >= n) {
            k = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << k << endl;

    vector<int> ans(n);
    fill(ans, n, k, k, 1, k, 0, 1);
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