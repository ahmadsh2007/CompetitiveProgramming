#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define str string // What a Python

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    str s; cin >> s;

    deque<int> small, big;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'B' && !big.empty()) big.pop_front();
        else if (s[i] == 'b' && !small.empty()) small.pop_front();
        else if (isupper(s[i]) && s[i] != 'B') big.push_front(i);
        else if (islower(s[i]) && s[i] != 'b') small.push_front(i);
    }

    // ! My old code
    // string ans = "";
    // while (!small.empty() || !big.empty()) {
    //     if (!small.empty() && !big.empty()) {
    //         if (small.back() < big.back()) {
    //             ans += s[small.back()];
    //             small.pop_back();
    //         } else {
    //             ans += s[big.back()];
    //             big.pop_back();
    //         }
    //     } else if (!small.empty()) {
    //         ans += s[small.back()];
    //         small.pop_back();
    //     } else {
    //         ans += s[big.back()];
    //         big.pop_back();
    //     }
    // }
    //
    // cout << ans << '\n';

    // ! Yaseen's code
    vector<int> IN(sz(s));

    while (!big.empty())
    {
        IN[big.back()] = 1;
        big.pop_back();
    }

    while (!small.empty())
    {
        IN[small.back()] = 1;
        small.pop_back();
    }

    for (int i = 0; i < (int)s.size(); i++)
        if (IN[i])
            cout << s[i];
        
    
    cout << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}