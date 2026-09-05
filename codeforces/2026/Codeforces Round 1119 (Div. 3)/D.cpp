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

int getMEX(const vector<int>& a,int L,int R){int len=R-L+1;vector<char> s(len+2);for(int i=L;i<=R;i++)if(a[i]>=0&&a[i]<=len)s[a[i]]=1;int m=0;while(s[m])m++;return m;}
int getMEX(const vector<int>& a){return getMEX(a,0,(int)a.size()-1);}

void solve() {
    int n; cin >> n;
    vector<int> ind;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            ind.push_back(i);
        }
    }

    if ((int) ind.size() == 1) {
        return void(cout << "NO\n");
    }

    str ans(n, 'A');
    if (ind.empty()) {
        cout << "YES\n" << ans << endl;
    }
    else {
        ans[ind[0]] = 'B';
        for (int i = 1; i < (int) ind.size(); ++i) {
            ans[ind[i]] = 'C';
        }
        cout << "YES\n" << ans << endl;
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