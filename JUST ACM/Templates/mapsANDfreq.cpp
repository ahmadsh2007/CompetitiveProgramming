#include <bits/stdc++.h>
using namespace std;

void preRUN(){
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main(){
    preRUN();

    // ! Code here:
    // Frequency Arrays

    // vector<int> freq(1000); // from 0 to 999

    // int n; cin >> n;
    // for (int i = 0; i < n; i++){
    //     int a; cin >> a;

    //     freq[a]++;
    // }

    // for(auto &x : freq) cout << x << ' ';

    // ! FREQUENCY ARRAY for Letters
    // int n; cin >> n;
    // string x; cin >> x;
    // vector<int> freq(26);
    // for(int i = 0; i < n; i++){
    //     freq[x[i] - 'a']++; // Let's say we entered 'a': a - a = 0, 'b': b - a = 1
    // }

    // for(auto &x : freq) cout << x;

    
    // ! Maps
    // ! map <key, value> m;

    map<int, int> c;
    c[5] = 1;
    c[6] = 7;
    c[4] = 2;

    // * first method to check map
    // map<int, int> ::iterator it;
    // for (it = c.begin(); it != c.end(); it++){
    //     // 3 ways of printing the value
    //     cout << (*it).first << ' ' << (*it).second << '\n';
    //     cout << it->first << ' ' << it->second << '\n';
    //     pair<int, int> temp = *it;
    //     cout << temp.first << ' ' << temp.second << '\n';
    // }

    // * second method to check map
    // for (auto a : c) cout << a.first << " " << a.second << '\n';
    // for (pair[a, b] : c) cout << a << ' ' << b << '\n';

    // ! Quick ex
    map<int, int> m;
    m[5] = 7;
    m[8] = 0;
    for (auto a : m) cout << a.first << ' ' << a.second << '\n';    // 5 7  \n  8 0
    cout << m.size() << '\n';                                       // 2
    m.erase(5);                                                     // it will remove 5 and its value (7)
    for (auto a : m) cout << a.first << ' ' << a.second << '\n';    // 8 0
    cout << m.empty() << '\n';                                      // not empty so 0
    m.erase(8);                                                     // it will remove 8 and its value (0)
    cout << m.empty() << '\n';                                      // empty so 1
}