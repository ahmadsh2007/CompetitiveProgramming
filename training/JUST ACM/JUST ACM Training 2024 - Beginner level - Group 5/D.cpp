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
    stack<char> c;
    int counter = 0;

    for (int i = 0; i < s.size(); i++){
        // Opening
        if(s[i] == '(' || s[i] == '{' || s[i] == '<' || s[i] == '['){
            c.push(s[i]);
            continue;
        }

        // Closing
        if(c.empty()){
            cout << "Impossible";                                                                   
            return;
        }

        if (!((c.top() == '(' && s[i] == ')') || (c.top() == '{' && s[i] == '}')
            ||(c.top() == '<' && s[i] == '>') || (c.top() == '[' && s[i] == ']'))){
            counter++;
        }
        c.pop();
    }

    if(!c.empty()) cout << "Impossible";
    else cout << counter;
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}