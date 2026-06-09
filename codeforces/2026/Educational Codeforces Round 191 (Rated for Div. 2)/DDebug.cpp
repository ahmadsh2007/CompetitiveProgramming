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

#define vi   vector<int>

void solve() {
    int n = 6;
    vi a{1, 2, 2, 3, 3, 1};

    set<int> types;
    for (int i = 0; i < n; ++i) types.insert(a[i]);
    
    if (types.size() == 1) return void(cout << "YES\n");

    set<int> unordered;
    set<int> unordered2;
    for (int i = 1; i < n; ++i) {
        if (unordered.find(a[i]) != unordered.end()) unordered2.insert(a[i]);
        if (unordered2.size() > 2) return void(cout << "NO\n");

        if (a[i] == a[i - 1]) continue;
        else unordered.insert(a[i - 1]);
    }

    for (auto &x : unordered2) {
        int idx = 0;
        for (int i = 0; i < n; ++i) if (a[i] == x) { idx = i; break; }
        for (int i = n - 1; i >= 0; --i) if (a[i] != x) {
            swap(a[i], a[idx]);
            break;
        }

        set<int> checked;
        int flag = 1;
        for (int i = 1; i < n; ++i) {
            if (checked.find(a[i]) != checked.end()) flag = 0;
            if (a[i] == a[i - 1]) continue;
            else checked.insert(a[i - 1]);
        }

        if (flag) return void(cout << "YES\n");
        a = {1, 2, 2, 3, 3, 1};
    }

    cout << "NO" << endl;
}

signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    while (TTT--) solve();
    return 0;
}