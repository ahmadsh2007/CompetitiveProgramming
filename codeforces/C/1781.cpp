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
    str s; cin >> s;

    vector<pair<int, char>> freq(26);
    for (int i = 0; i < 26; ++i) freq[i].second = 'a' + i;
    for (int i = 0; i < n; ++i) freq[s[i] - 'a'].first++;

    sort(rall(freq));
    int best = 1, ans = n;
    for (int i = 1; i <= 26; ++i) {
        if (n % i) continue;

        int unchanged = 0;
        for (int j = 0; j < i; ++j) unchanged += min(freq[j].first, n / i);
        if (n - unchanged < ans) {
            best = i;
            ans = n - unchanged;
        }
    }

    map<char, int> m;
    for (int i = 0; i < best; ++i) m[freq[i].second] = n / best;

    str out;
    for (int i = 0; i < n; ++i) out += ' ';
    for (int i = 0; i < n; ++i) {
        if (m[s[i]] > 0) {
            out[i] = s[i];
            m[s[i]]--;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (out[i] != ' ') continue;

        while (!m.empty() && (*m.begin()).second == 0) m.erase(m.begin());
        char ch = (*m.begin()).first;
        out[i] = ch;
        m[ch]--;
    }

    cout << ans << endl;
    cout << out << endl;
}

const int TESTCASES = 1;
signed main() {

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