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

const int MOD = 998244353;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n); cin >> a;

    int ans = 0;
    for (int bit = 0; bit < 31; ++bit) {
        int sum = 0;

        int on = 0, off = 0, onCnt = 0, offCnt = 0;
        for (int i = 0; i < n; ++i) {
            on  = (on + onCnt) % MOD;
            off = (off+offCnt) % MOD;

            if (a[i] & (1 << bit)) {
                swap(on, off);
                swap(onCnt, offCnt);

                on++;
                onCnt++;
            }
            else {
                off++;
                offCnt++;
            }

            sum = (sum + on) % MOD;
        }

        ans = (ans + (sum << bit)) % MOD;
    }

    cout << ans << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}