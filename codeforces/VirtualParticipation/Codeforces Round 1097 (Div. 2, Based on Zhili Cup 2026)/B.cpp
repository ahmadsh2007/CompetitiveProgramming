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

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int getMEX(const vector<int>& a,int L,int R){int len=R-L+1;vector<char> s(len+2);for(int i=L;i<=R;i++)if(a[i]>=0&&a[i]<=len)s[a[i]]=1;int m=0;while(s[m])m++;return m;}
int getMEX(const vector<int>& a){return getMEX(a,0,(int)a.size()-1);}

void solve() {
    int n; cin >> n;
    vi a(n);
    multiset<int> ms;

    int mx = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ms.insert(a[i]);
        mx = max(mx, a[i]);
    }

    vector<int> ans;
    ans.push_back(mx);
    ms.erase(ms.find(mx));

    int needed = 0;
    while (ans.size() < n) {
        auto it = ms.find(needed);
        if (it != ms.end()) {
            ans.push_back(needed);
            ms.erase(it);
            needed++;
        } else break;
    }

    for (int x : ms) ans.push_back(x);

    int print = 0;
    int curMex = 0;
    set<int> seen;
    for (int i = 0; i < n; ++i) {
        seen.insert(ans[i]);
        while (seen.count(curMex)) curMex++;
        print += curMex;
    }

    print += ans[0] * n;
    cout << print << endl;
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