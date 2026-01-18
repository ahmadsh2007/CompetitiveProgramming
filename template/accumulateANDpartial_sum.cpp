#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
using ll = long long;

ll op(ll a, ll b) {
    return a * b;
}

void print(vector<ll> &a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
}

int main() {
    vector<ll> a = {5, 10, 15};
    int initial = 0;
    ll sum = accumulate(all(a), initial);
    // * It sums all elements of the vector starting from the initial value 0, so the result is 5 + 10 + 15 = 30.
    cout << sum << endl;

    initial = 1;
    sum = accumulate(all(a), initial, op);
    // * It uses the binary function op instead of addition. Since op multiplies two numbers, the result is 1 * 5 * 10 * 15 = 750.
    cout << sum << endl;

    vector<ll> b = {5, 10, 15};
    int n = b.size();
    vector<ll> result(n);

    partial_sum(all(b), result.begin());
    // * Each element in the result is the sum of all elements up to that position (prefix sum), so the result is 5 15 30.
    print(result, n);

    vector<ll> result2(n);
    partial_sum(all(b), result2.begin(), op);
    // * It computes the prefix product using op, so each element is the product of all previous elements, resulting in 5 50 750.
    print(result2, n);
}
