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
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

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
    for (auto &x : a) cin >> x;

    int target = *max_element(all(a)) - *min_element(all(a));

    for (int i = 0; i < n; ++i) if (abs(a[i]) >= target) { cout << "NO\n"; return;}

    cout << "YES\n";

    vector<int> pos, neg;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0) neg.push_back(a[i]);
        else pos.push_back(a[i]);
    }

    sort(all(pos));
    sort(rall(neg));

    int tot = 0;
    bool go = (pos.size() > neg.size() ? 0 : 1);
    while (!pos.empty() || !neg.empty()) {
        if (tot == 0)
        {
            if (go && !neg.empty())
            {
                tot += neg.back();
                cout << neg.back() << ' ';
                neg.pop_back();
            }
            else if (!pos.empty())
            {
                tot += pos.back();
                cout << pos.back() << ' ';
                pos.pop_back();
            }
            else go = !go;
        }

        if (tot > 0)
        {
            if (neg.empty()) break;
            tot += neg.back();
            cout << neg.back() << ' ';
            neg.pop_back();
        }
        else
        {
            if (pos.empty()) break;
            tot += pos.back();
            cout << pos.back() << ' ';
            pos.pop_back();
        }
    }

    for (int i = 0; i < (int) pos.size(); ++i) cout << pos[i] << ' ';
    for (int i = 0; i < (int) neg.size(); ++i) cout << neg[i] << ' ';
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef LOCAL
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}