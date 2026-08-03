#include <bits/stdc++.h>
using namespace std;

int n, m;

struct SegTree {
    int size;
    vector<vector<long long>> sums;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        sums.assign(2 * size, vector<long long>(41));
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            for (int j = 0; j <= 40; ++j) sums[x][j] = 0;
            sums[x][v] = 1;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        for (int c = 0; c <= 40; ++c) {
            sums[x][c] = sums[2 * x + 1][c] + sums[2 * x + 2][c];
        }
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    vector<long long> getDifferent(int l, int r, int x, int lx, int rx) {
        if (lx >= r or rx <= l) return vector<long long>(41);
        if (lx >= l and rx <= r) return sums[x];

        int mid = (lx + rx) / 2;
        vector<long long> s1 = getDifferent(l, r, 2 * x + 1, lx, mid);
        vector<long long> s2 = getDifferent(l, r, 2 * x + 2, mid, rx);
        for (int i = 0; i <= 40; ++i) s1[i] += s2[i];

        return s1;
    }
    int getDifferent(int l, int r) {
        vector<long long> temp = getDifferent(l, r, 0, 0, size);
        int res = 0;
        for (int i = 0; i <= 40; ++i) if (temp[i]) res++;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    SegTree st;
    st.init(n + 1);

    for (int i = 1; i <= n; ++i) {
        int v; cin >> v;
        st.set(i, v);
    }

    for (int i = 1; i <= m; ++i) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; cin >> l >> r;
            cout << st.getDifferent(l, r + 1) << endl;
        }
        else {
            int i, v; cin >> i >> v;
            st.set(i, v);
        }
    }
}