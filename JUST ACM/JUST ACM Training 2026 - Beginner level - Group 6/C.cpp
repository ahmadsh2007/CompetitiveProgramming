#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
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

// PreCompute
long long arr[200001];
long long digit[200001];
long long pre[200002];

void preCompute(){
    for (int i = 0; i < 200001; i++) arr[i] = i + 1;
    for (int i = 0; i < 200001; i++) {
        int sum = 0, temp = arr[i];
        while(temp > 9) {
            sum += temp % 10;
            temp /= 10;
        }
        digit[i] = sum + temp;
    }
    for (int i = 1; i <= 200001; i++) pre[i] = pre[i - 1] + digit[i - 1];
}

void solve() {
    int n; cin >> n;
    cout << pre[n] << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    preCompute();

    ull T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}