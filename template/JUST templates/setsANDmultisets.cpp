// Sets has some rules
// first    rule:       They are sorted
// second   rule:       No duplicates

// Multisets is like Sets but allows duplicates
// a.k.a. first rule applies but not the second one

// Sets have no random access like vectors.

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
    // ? Set & Multiset
    // Let's say we want to enter {2, 3, 2, 5, 2, 7, 1, 1, 3}
    // * ARRAY          :   {2, 3, 2, 5, 2, 7, 1, 1, 3}
    // * SET            :   {1, 2, 3, 5, 7}
    // * MULTISET       :   {1, 1, 2, 2, 2, 3, 3, 5, 7}

    vector<int> v({2, 3, 2, 5, 2, 7, 1, 1, 3});
    // vector<int> v = {2, 3, 2, 5, 2, 7, 1, 1, 3};

    set<int> s;
    // set<int> s({2, 3, 2, 5, 2, 7, 1, 1, 3});
    // set<int> s(v.begin(), v.end());

    // you can order them in the opposite way
    // set<int, greater<int>> s(v.begin(), v.end());

    // to insert from vector to the SET
    for (auto i : v) {
        s.insert(i); // O(log(n))
        for (auto j : s) cout << j << ' ';
        cout << '\n';
    }

    // Some functions of SET
    s.clear();
    s.empty(); // if empty it return true, and the opposite

    auto X = 1;
    s.erase(X);
    s.find(X);
   *s.find(X);
    s.lower_bound(X); // E >= X
    s.upper_bound(X); // E > X

    for(auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
    for(auto it = s.rbegin(); it != s.rend(); it++) cout << *it << ' ';


    // MULTISETS
    // everything applies on sets also apply on sets
    multiset<int> ms;

    // the differences
    ms.erase(X); // it applies on all the duplicates
    ms.erase(ms.find(X)); // to delete a number once
    ms.count(X); // returns the number of duplicates
}