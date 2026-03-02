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

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl '\n'
#define int long long
#define str string // What a Python

#define vi   vector<int>
#define vill vector<ll>
#define read(v) for (auto &x : v) cin >> x;
#define cin(v)  for (auto &x : v) cin >> x;
#define cout(v) for (auto &x : v) cout << x << ' ';

using ll  = long long;
using ull = unsigned long long;

using u128 = unsigned __int128;
using i128 = __int128;

const int MOD = 1e9 + 7;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

// void solve() {
//     int n; cin >> n;
//     vector<vector<int>> blogs(n);
//     for (int i = 0; i < n; i++) {
//         int l; cin >> l;
//         vector<int> tmp(l); cin >> tmp;
//         set<int> mentioned;
//         vector<int> ret;
//         for (int i = 0; i < (int) tmp.size(); ++i) {
//             if (mentioned.find(tmp[i]) == mentioned.end()) {
//                 ret.push_back(tmp[i]);
//                 mentioned.insert(tmp[i]);
//             }
//         }
//         reverse(all(ret));
//         blogs[i] = ret;
//     }

//     sort(all(blogs));
//     vi ans;
//     for (int i = 0; i < n; ++i) ans.insert(ans.end(), all(blogs[i]));

//     map<int, int> mentioned;
//     n = (int) ans.size();
//     for (int i = 0; i < n; ++i) {
//         if (mentioned[ans[i]] == 0) {
//             cout << ans[i] << ' ';
//             mentioned[ans[i]]++;
//         }
//     }
//     cout << endl;
// }

vector<int> vis(10000000);
int visTimer = 0;

void solve() {
    int n; cin >> n;
    vector<vector<int>> blogs(n);
    for (int i = 0; i < n; ++i) {
        int l; cin >> l;
        vi tmp(l); cin >> tmp;
        reverse(all(tmp));
        vi unique;
        set<int> seen;
        for(auto x : tmp) {
            if (seen.find(x) == seen.end()) {
                unique.push_back(x);
                seen.insert(x);
            }
        }
        blogs[i] = unique;
    }

    visTimer++;
    vector<bool> used(n);
    vi q;

    for (int step = 0; step < n; ++step) {
        int bestIDX = -1;
        vi best;
        
        for (int i = 0; i < n; ++i) {
            if (used[i]) continue;
            
            vi curDiff;
            for (int x : blogs[i]) if (vis[x] != visTimer) curDiff.push_back(x);
            
            if (bestIDX == -1 || curDiff < best) {
                bestIDX = i;
                best = curDiff;
            }
        }
        
        used[bestIDX] = true;
        for (int x : best) {
            q.push_back(x);
            vis[x] = visTimer;
        }
    }

    for (int i = 0; i < q.size(); i++) cout << q[i] << ' ';
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    #ifndef ONLINE_JUDGE
    #if __has_include("../../Utils/debug.h")
      freopen("../../Utils/input.txt", "r", stdin);
      freopen("../../Utils/output.txt", "w", stdout);
    #else
      freopen("../../../Utils/input.txt", "r", stdin);
      freopen("../../../Utils/output.txt", "w", stdout);
    #endif
    #endif

    // print("Leeking"); // Yes, it works and yes, it's Python

    ull TTT = 1;
    if (TESTCASES == 1) cin >> TTT;
    else if (TESTCASES == 2) {
    #ifndef ONLINE_JUDGE
      cin >> TTT;
    #endif
    }
    while (TTT--) solve();
    return 0;
}