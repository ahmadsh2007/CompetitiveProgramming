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
    int n, q; cin >> n >> q;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    vector<int> ind(n + 1);
    for (int i = 1; i <= n; ++i) {
        ind[p[i]] = i;
    }
    cerr << p << endl << ind << endl;

    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        if (ind[k] < l or ind[k] > r) {
            cout << "-1 ";
            continue;
        }

        if (p[(l + r) / 2] == k) {
            cout << "0 ";
            continue;
        }

        int d = 0, u = 0;
        int badD = 0, badU = 0;
        int ll = l, rr = r;
        while (true) {
            int mid = (ll + rr) / 2;
            if (mid == ind[k]) break;
            else if (mid < ind[k]) {
                u++;
                if (p[mid] > k) badU++;
                ll = mid + 1;
            }
            else {
                d++;
                if (p[mid] < k) badD++;
                rr = mid - 1;
            }
        }

        if (u > k - 1 or d > n - k) {
            cout << "-1 ";
        }
        else {
            cout << 2 * max(badU, badD) << ' ';
        }
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