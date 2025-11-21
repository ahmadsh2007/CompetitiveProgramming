#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();


void solve(){
    int n; cin >> n;

    int mx = -1, afterMx = -1, maxIndex = -1;
    int s[n];
    for (int i = 0; i < n; i++){
        cin >> s[i];
        if (s[i] >= mx){
            afterMx = mx;
            mx = s[i];
            maxIndex = i;
        } else if (s[i] > afterMx) afterMx = s[i];
    }

    for (int i = 0; i < n; i++){
        if(i == maxIndex) cout << s[i] - afterMx << " ";
        else cout << s[i] - mx << " ";
    }

    cout << "\n";
}

int main(){
// For inputs and outputs operations
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // Use this template to solve, if you have test cases then don't comment, and if you don't have then comment t and while.
    int t; std::cin >> t;
    while(t--)
        solve();
}