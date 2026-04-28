#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct stars {
    int x;
    int y;
    int z;
};

bool cmp(int x, int y) {
    if (x > y) return true;
    return false;
}

bool cmp2(int x, int y) {
    if (x < y) return true;
    return false;
}

bool cmpStars(stars a, stars b) {
    if (a.x < b.x) return true;
    return false;
}

bool cmpStars2(stars a, stars b) {
    if (a.x > b.x) return true;
    return false;
}

int main() {
    const int N = 6;
    stars a[N];

    // sort(array, array + N) // Error

    int b[N] = {3, 2, 5, 0, 16, 7};
    sort(b, b + N);                 // returns {0, 2, 3, 5, 7, 16}
    sort(b, b + N, greater<int>()); // returns {16, 7, 5, 3, 2, 0}
    sort(b, b + N, cmp);            // returns {16, 7, 5, 3, 2, 0}
    sort(b, b + N, cmp2);           // returns {0, 2, 3, 5, 7, 16}
    // for (int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];

    // * Now back to array of stars, if used sort normally the program would return an error
    // * Let's say this is the input:
    // *    x       y       z
    // *    1       2       3
    // *    2       2       3
    // *    5       7       8
    // *    3       9       4
    // *    1       3       3
    // *    14      23      99
    for (int i = 0; i < N; i++) cin >> a[i].x >> a[i].y >> a[i].z;
    cout << "\n";
    sort(a, a + N, cmpStars);
    for (int i = 0; i < N; i++) cout<< a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
    // * Expected output:
    // *    x       y       z
    // *    1       2       3
    // *    1       3       3
    // *    2       2       3
    // *    3       9       4
    // *    5       7       8
    // *    14      23      99

    cout << '\n';
    sort(a, a + N, cmpStars2);
    for (int i = 0; i < N; i++) cout<< a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
    // * Expected output:
    // *    x       y       z
    // *    14      23      99
    // *    5       7       8
    // *    3       9       4
    // *    2       2       3
    // *    1       2       3
    // *    1       3       3
}