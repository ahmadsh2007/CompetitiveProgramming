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
const long long INF = 2e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct Node {
    int a, b, c;
    bool canChange;

    bool operator<(const Node& other) const {
        return (a + b + c) > (other.a + other.b + other.c);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<Node> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].a >> a[i].b >> a[i].c;
    }

    auto cost = [&](int a, int b, int c, int target) -> int {
        if (target <= a + b + c) return 0;
        if (a == b and b == c) return INF;

        int diff = target - (a + b + c);
        if (a <= b and b <= c) {
            return diff + 2 + 2 * min(b - a, c - b);
        }
        return diff;
    };
    auto check = [&](int mid) -> bool {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += cost(a[i].a, a[i].b, a[i].c, mid);
            if (res > k) return false;
        }
        return true;
    };

    int l = -9e9, r = 3e18;
    int mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
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