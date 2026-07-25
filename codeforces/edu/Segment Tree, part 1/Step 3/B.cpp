#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<int> sums;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        sums.assign(2 * size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        return;
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int Pth(int i, int x, int lx, int rx) {
        // printf("i: %d, lx: %d, rx: %d\n", i, lx, rx);
        if (rx - lx == 1) {
            // printf("\n");
            set(lx, 0);
            return lx;
        }

        int mid = lx + (rx - lx) / 2;
        if (sums[2 * x + 2] >= i) {
            return Pth(i, 2 * x + 2, mid, rx);
        }
        else {
            return Pth(i - sums[2 * x + 2], 2 * x + 1, lx, mid);
        }
    }
    int Pth(int i) {
        return Pth(i + 1, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    SegTree st;
    st.init(n + 1);
    
    vector<int> inversions(n + 1);
    for (int i = 1; i <= n; ++i) cin >> inversions[i];

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) st.set(i, 1);

    for (int i = n; i > 0; --i) {
        ans[i] = st.Pth(inversions[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
}