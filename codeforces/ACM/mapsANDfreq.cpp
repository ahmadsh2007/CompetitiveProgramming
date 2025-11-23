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
    // Frequency Arrays
    vector<int> freq(1000); // from 0 to 999

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int a; cin >> a;

        freq[a]++;
    }

    for(auto &x : freq) cout << x << ' ';
}