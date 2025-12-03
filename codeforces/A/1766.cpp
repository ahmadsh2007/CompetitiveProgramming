#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

using i64 = long long;
using ll = long long;
using u64 = unsigned long long;
using ull = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

bool check(int x){
    int digitsCount = 0;
    int zerosCount  = 0;

    while(x){
        if (x % 10 == 0) zerosCount++;
        digitsCount++;
        x /= 10;
    }

    return zerosCount == digitsCount - 1;
}

void solve(const vector<int> &roundNumbers) {
    int n; cin >> n;

    int ans = 0;
    for(int i = 0; i < roundNumbers.size(); i++) {
        if(roundNumbers[i] <= n) ans++;
        else break;
    }

    cout << ans << '\n';
}

vector<int> roundNumbers;

#undef int
int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    for (int i = 1; i <= 999999; i++) if (check(i)) roundNumbers.push_back(i);

    ull T = 1;
    cin >> T;
    while (T--) solve(roundNumbers);
    return 0;
}