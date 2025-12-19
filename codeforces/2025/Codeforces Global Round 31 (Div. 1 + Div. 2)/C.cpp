#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "../Utils/debug.h"
#endif

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

void solve() {
    int n, k; cin >> n >> k;

    if (k % 2) {
        for (int i = 0; i < k; i++)
            cout << n << ' ';
    } else {
        for (int i = 0; i < k - 2; ++i)
            cout << n << " ";

        int num1 = 1, num2;
        while(num1 << 1 <= n) num1 <<= 1;
        num2 = n - num1;

        int plus = 0;
        // 2 ^ 29 is less than 10 ^ 9 and 2 ^ 30 is bigger than 10 ^ 9 so we chose 2 ^ 29
        // I think we can also use 2 ^ 30 but I don't know I can't check AI or anyone mid contest so I'll do the checking after the contest finishes
        for (int i = 29; i >= 0; i--) {
            int compare = 1LL << i;
            // Ahhhh, writing the condition for the if statement is suffering
            // What I can say is num1 + num2 = n, num1 >= num2 and must be less than or equal to n
            // to keep this condition true we need to add a value less than num2 (bec num1 = n - num2)
            // so I think this is the correct condition
            if ((!(n & compare)) && ((plus + compare) <= num2)) plus += compare;

            // And.............................. the code failed
            // Enough for today, league of legends is calling me :(
        }

        cout << num1 + plus << ' ' << num2 + plus;
    }

    cout << '\n';
}

#undef int
int main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}