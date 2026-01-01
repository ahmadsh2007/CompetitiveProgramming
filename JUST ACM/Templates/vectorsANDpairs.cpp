#include <bits/stdc++.h>
using namespace std;


int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int n = 5;
    vector<int> v(n);

    // * All of these works, the first is the best and the third second best
    for(auto &x: v) cin >> x;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++) cin >> v[i];


    // ! pointers
    cout << *(v.begin() + 2) << '\n';


    // ! sorting
    // * We use pointer inside sort function
    sort(v.begin(), v.end());
    // * If we want the first 2 elements
    sort(v.begin(), v.end() + 2);
    // * start from the highest
    sort(v.rbegin(), v.rend());
    // test
    for (auto &x: v) cout << x << ' ';



    // ! now pairs
    pair<int, int> p;
    int  x, y; cin >> x >> y;
    p = make_pair(x, y);
    p = {x, y};

    cout << p.first << ' ' << p.second << endl;

    

    // ! we use vectors to create multiple pairs
    vector<pair<int, int>> v2;
    v2.push_back(make_pair(x, y));
    v2.push_back({x, y});
    cout << v2[0].first << ' ' << v2[0].second << '\n';


    int n; cin >> n;
    vector<pair<int, int>> v3(n);
    for(auto &x: v3) {
        cin >> x.first >> x.second;
    }
    for (auto &x : v3) cout << x.first << ' ' << x.second << '\n';

    sort(v3.begin(), v3.end());


    // ! Sort by second value
    vector<pair<int, int>> a;
    sort(a.begin(), a.end(), [](const pair<int,int>& p1,
                                const pair<int,int>& p2) {
        return p1.second < p2.second;
    });

}