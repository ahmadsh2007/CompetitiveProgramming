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

    long long getSeg(int l, int r, int x, int lx, int rx) {
        if (r <= lx or rx <= l) return 0;
        if (lx >= l and rx <= r) return sums[x];

        int mid = lx + (rx - lx) / 2;
        long long c1 = getSeg(l, r, 2 * x + 1, lx, mid);
        long long c2 = getSeg(l, r, 2 * x + 2, mid, rx);
        return c1 + c2;
    }
    long long getSeg(int l, int r) {
        return getSeg(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
    
    vector<int> ans(n + 1);
    auto solve = [&]() -> void {
        SegTree st;
        st.init(2 * n + 2);
        vector<int> left(n + 1);

        for (int i = 1; i <= 2 * n; ++i) {
            if (left[a[i]]) {
                ans[a[i]] += st.getSeg(left[a[i]] + 1, i);
                st.set(left[a[i]], 0);
            }
            else {
                left[a[i]] = i;
                st.set(left[a[i]], 1);
            }
        }
    };

    solve();
    reverse(a.begin() + 1, a.end());
    solve();

    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}