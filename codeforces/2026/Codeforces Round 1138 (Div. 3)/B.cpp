/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

template<class T>istream& operator>>(istream& in, vector<T>& v){for(auto& x:v) in>>x;return in;}
template<class T>ostream& operator<<(ostream& out, vector<T>& v){for(auto& x:v) out<<x<<' ';return out;}

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const long long INF = 1e18;
const int MOD = 1e9 + 7;

void solve() {
    int n, k, p; cin >> n >> k >> p;
    vector<int> a(n); cin >> a;
    sort(all(a));
    int ans = 0;
    int i = 0;
    while (i < n) {
        int tot = 0;
        bool can = false;
        int j = i;
        for (; j < i + k and j < n; ++j) {
            tot += a[j];
            if (j == i + k - 1) {
                can = true;
            }
        }

        if (can) {
            ans += max(tot, p);
        }
        else ans += tot;

        i = j;
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