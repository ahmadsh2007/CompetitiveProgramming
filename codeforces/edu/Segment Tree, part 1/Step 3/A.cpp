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

    void set(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = 1;
            return;
        }

        int mid = lx + (rx - lx) / 2;
        if (i < mid) {
            set(i, 2 * x + 1, lx, mid);
        }
        else {
            set(i, 2 * x + 2, mid, rx);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        return;
    }
    void set(int i) {
        set(i, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 0ll;
        if (lx >= l and rx <= r) return sums[x];

        int mid = lx + (rx - lx) / 2;
        int c1 = sum(l, r, 2 * x + 1, lx, mid);
        int c2 = sum(l, r, 2 * x + 2, mid, rx);
        return c1 + c2;
    }
    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    SegTree st;
    st.init(n + 1);

    vector<int> ans(n + 1);

    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        st.set(v);
        if (v != n) ans[i] = st.sum(v + 1, n + 1);
    }

    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}