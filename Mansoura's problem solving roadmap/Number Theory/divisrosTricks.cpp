#include <bits/stdc++.h>

using namespace std;

void printVector(const vector<int> & a) {
    for (int i = 0; i < a.size(); i++) cout << a[i] << " \n"[i == a.size() - 1];
}

const int N = 1e5;
vector<int> divisors[N + 1];

void pre() {
    for (int i = 1; i <= N; i++) 
    {
        for (int j = i; j <= N; j += i)
        {
            divisors[j].push_back(i);
        }
    }


}

signed main() {



}