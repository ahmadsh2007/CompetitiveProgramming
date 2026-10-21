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

const int N = 1e6 + 5;
vector<int> primes, spf(N+1);
static const int PrimesAndSPF=[](){
    for(int i=2;i<=N;i++){ if(!spf[i]) spf[i]=i,primes.push_back(i); for(int p:primes){ if(1LL*p*i>N) break; spf[p*i]=p; if(p==spf[i]) break; } } return 0;
}();

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<vector<int>> divs(n);
    map<vector<int>, int> cnt;
    for (int i = 0; i < n; ++i) {
        vector<int> cur{1};
        int x = a[i];
        while (x != 1) {
            int p = spf[x];
            if (cur.back() == p) {
                cur.pop_back();
            }
            else {
                cur.push_back(p);
            }

            x /= spf[x];
        }
        divs[i] = cur;
        cnt[cur]++;
    }

    int ans = 0;
    set<int> odd;
    for (int j = 0; j < n; ++j) {
        for (int k = 1; k < (int) divs[j].size(); ++k) {
            int p = divs[j][k];
            if (!odd.erase(p)) odd.insert(p);
        }
        if (odd.size() <= 7) {
            vector<int> key{1};
            key.insert(key.end(), odd.begin(), odd.end());
            auto it = cnt.find(key);
            if (it != cnt.end()) ans += it->second;
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