#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a;
    int l = 0, r = LLONG_MAX, mid, ans, goal;
    while(l <= r){
        mid = (l + r) / 2;
        if (a[mid] > goal) {
            ans = mid + 1;
            r = mid - 1;
        } else l = mid + 1;
    }

    // Lower bound returns the iterator of the first element bigger than or equal to X
    // You can turn it to an index by doing the following:
    int idx = lower_bound(a.begin(), a.end(), goal) - a.begin();
    // Upper bound returns strictly larger than X
    int idx_upper = upper_bound(a.begin(), a.end(), goal) - a.begin();

    // ! in sets and multisets
    // upper bound and lower bound return the address of the target
    set <int> s;
    // ! this is wrong
    // int address = lower_bound(s.begin(), s.end(), goal);

    // * This is right, also it's auto not int
    auto address = s.lower_bound(goal);
    cout << *address;
    auto address_upper = s.upper_bound(goal);
    cout << *address_upper;

    // * Same for multisets
}