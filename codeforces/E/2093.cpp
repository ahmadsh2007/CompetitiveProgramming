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

int getMEX(const vector<int>& a,int L,int R){int len=R-L+1;vector<char> s(len+2);for(int i=L;i<=R;i++)if(a[i]>=0&&a[i]<=len)s[a[i]]=1;int m=0;while(s[m])m++;return m;}
int getMEX(const vector<int>& a){return getMEX(a,0,(int)a.size()-1);}

int timer = 0;
vector<int> nums(2e5 + 5);

bool check(const vector<int> & a, int k, int mid) {
    timer++;
    int cnt = 0;
    int curMex = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        if (a[i] <= (int) a.size() + 1) nums[a[i]] = timer;
        while(nums[curMex] == timer) curMex++;

        if (curMex >= mid) {
            cnt++;
            timer++;
            curMex = 0;
        }
    }

    return cnt >= k;
}

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); cin >> a;

    int l = 0, r = 1e9, mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(a, k, mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans << endl;
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
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}