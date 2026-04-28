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

void solve() {
    int n; cin >> n;
    map<int, int> a;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }

    if(a.size() == 1){
        cout << "YES\n";
        return;
    }

    if(a.size() == 2){
        auto i = a.begin();
        int numberOne = (*i).second;
        int numberTwo = next(i)->second;
        cout << ((abs(numberOne - numberTwo) <= 1) ? "YES\n" : "NO\n");
        return;
    } else cout << "NO\n";
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}