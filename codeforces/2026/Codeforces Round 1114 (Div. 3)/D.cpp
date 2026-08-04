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
    vector<int> ans(n);
    map<int, int> freq;
    set<int> has;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        has.insert(a[i]);
    }

    if (has.find(0) == has.end()) return void(cout << "-1\n");

    int tot = 0;
    map<int, int> holder;
    auto it = next(has.begin());
    int last = 0;
    while (it != has.end()) {
        auto temp = prev(it);

        int diff = *it - *temp;
        int div = freq[*temp];
        if (diff <= 0 or diff % div != 0) return void(cout << "-1\n");

        if ((diff / div) <= last) return void(cout << "-1\n");

        holder[*temp] = (diff / div);
        last = (diff / div);

        it = next(it);
    }
    int mx = 0;
    for (auto &[key, ans] : holder) mx = max(mx, ans);

    for (int i = 0; i < n; ++i) {
        cout << (holder[a[i]] != 0 ? holder[a[i]] : mx + 1) << " \n"[i == n - 1];
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