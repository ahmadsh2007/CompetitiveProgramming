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
    str s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    queue<int> p1;
    queue<int> p2;

    for(int i = 0; i < s1.size(); i+=2){
        if(s1[i] == 'A') p1.push(14);
        else if(s1[i] == 'K') p1.push(13);
        else if(s1[i] == 'Q') p1.push(12);
        else if(s1[i] == 'J') p1.push(11);
        else if(s1[i] == 'T') p1.push(10);
        else p1.push(s1[i] - '0');
    }

    for(int i = 0; i < s2.size(); i+=2){
        if(s2[i] == 'A') p2.push(14);
        else if(s2[i] == 'K') p2.push(13);
        else if(s2[i] == 'Q') p2.push(12);
        else if(s2[i] == 'J') p2.push(11);
        else if(s2[i] == 'T') p2.push(10);
        else p2.push(s2[i] - '0');
    }

    int counter = 0;
    while(!p1.empty() && !p2.empty() && (counter++ < (13 * 13))){
        if(p1.front() > p2.front()){
            p1.push(p2.front());
        } else if (p2.front() > p1.front()){
            p2.push(p1.front());
        } else {
            p1.push(p1.front());
            p2.push(p2.front());
        }
        p1.pop();
        p2.pop();
    }

    if (p1.empty()) cout << "player 2\n";
    else if (p2.empty()) cout << "player 1\n";
    else cout << "draw\n";
}

int main() {
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    // print("Ahmad"); // Yes, it works and yes, it's Python

    int T = 1;
    cin >> T;

    str x; getline(cin, x);
    while (T--) solve();
    return 0;
}