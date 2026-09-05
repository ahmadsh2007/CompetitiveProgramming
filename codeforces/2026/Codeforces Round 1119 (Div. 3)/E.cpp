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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0) {
            int l = max(0ll, i - a[i] + 1);
            int r = min(n - 1, i + a[i] - 1);
            prefix[l]++;
            prefix[r + 1]--;
        }
    }
    for (int i = 1; i < n; ++i) prefix[i] += prefix[i - 1];
    for (int i = 0; i < n; ++i) prefix[i] = min(1ll, prefix[i]);

    int cant = true;
    for (int i = 0; i < n; ++i) {
        if (prefix[i] == 0) {
            cant = false;
        }
    }
    if (cant) {
        return void(cout << -1 << endl);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 and prefix[i]) {
            return void(cout << -1 << endl);
        }
    }

    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) continue;
        if (i - a[i] >= 0 and prefix[i - a[i]] == 0) {
            nums[i - a[i]] = 1;
        } else if (i + a[i] < n and prefix[i + a[i]] == 0) {
            nums[i + a[i]] = 1;
        } else {
            return void(cout << -1 << endl);
        }
    }

    int hasOne = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i]) hasOne = 1;
    }
    if (hasOne == 0) {
        for (int i = 0; i < n; ++i) {
            if (prefix[i] == 0) {
                nums[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << nums[i];
    }
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}