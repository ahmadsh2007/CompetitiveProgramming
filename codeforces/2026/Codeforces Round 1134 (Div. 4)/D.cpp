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
    int n; cin >> n;
    str s; cin >> s;

    int ans = 0;
    int l = 0, r = n - 1;
    map<char, char> to;
    for (int i = 0; i < 26; ++i) {
        to[(char) 'a' + i] = (char) 'a' + i;
    }
    // while (l < r) {
    //     s[l] = to[s[l]];
    //     s[r] = to[s[r]];
    //     if (s[l] != s[r]) {
    //         bool flag = s[l] < s[r];
    //         if (flag) {
    //             int d = s[r] - s[l];
    //             ans += d;
    //             to[s[r]] -= d;
    //         }
    //         else {
    //             int d = s[l] - s[r];
    //             ans += d;
    //             to[s[l]] -= d;
    //         }
    //     } 
    //     l++;
    //     r--;
    // }
    vector<bool> converted(26);
    while (l < r) {
        if (s[l] != s[r]) {
            int left = min(s[l], s[r]) - 'a';
            int rght = max(s[l], s[r]) - 'a';
            for (int i = left; i < rght; ++i) {
                converted[i] = true;
            }
        }
        l++;
        r--;
    }

    for (int i = 0; i < 26; ++i) {
        if (converted[i]) {
            ans++;
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