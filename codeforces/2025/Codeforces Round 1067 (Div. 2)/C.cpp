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

i64 maxSubarraySum(vector<i64> &a) {
    i64 maxSum = a[0], curSum = a[0];
    for (u64 i = 1; i < a.size(); i++) {
        curSum = max(a[i], curSum + a[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

void solve() {
    // ! Sadly failed

    int n, k; cin >> n >> k;
    vector<i64> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;

    bool zeros = 1;
    for(auto x : b) if (x != 0) zeros = false;

    if(zeros) { cout << maxSubarraySum(a) << '\n'; return; }

    vector<i64> aa = a;
    for(int turn = 0; turn < k; turn++){
        int i = max_element(aa.begin(), aa.end()) - aa.begin();

        if(turn % 2 == 0) aa[i] += b[i];
        else aa[i] -= b[i];
    }

    cout << maxSubarraySum(aa) << '\n';
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