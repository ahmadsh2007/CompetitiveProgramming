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
    int n, k; cin >> n >> k;
    vector<int> a(n); cin >> a;

    int best = -1, bestI = -1, bestJ = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(a[i], a[j]);

            vector<int> seen(n + 1);
            vector<int> vec;
            int mex = 0;
            for (int i = 0; i < n; ++i) {
                seen[a[i]] = 1;
                while (seen[mex]) {
                    mex++;
                }
                vec.push_back(mex);
            }
            sort(rall(vec));
            int cur = vec[k - 1];

            swap(a[i], a[j]);

            if (cur > best) {
                best = cur;
                if (i == j) {
                    bestI = bestJ = -1;
                }
                else {
                    bestI = i;
                    bestJ = j;
                }
            }
        }
    }

    if (bestI == -1) {
        cout << -1 << endl;
    }
    else {
        cout << bestI + 1 << ' ' << bestJ + 1 << endl;
    }

}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}