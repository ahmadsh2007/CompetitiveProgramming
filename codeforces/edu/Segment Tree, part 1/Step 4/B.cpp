#include <bits/stdc++.h>
using namespace std;

int r, n, m;

struct Matrix {
    int a, b;
    int c, d;

    Matrix operator*(const Matrix & other) const {
        return Matrix(
            ((a * other.a % r) + (b * other.c % r)) % r,
            ((a * other.b % r) + (b * other.d % r)) % r,
            ((c * other.a % r) + (d * other.c % r)) % r,
            ((c * other.b % r) + (d * other.d % r)) % r
        );
    }

    Matrix & operator*=(const Matrix & other) {
        *this = *this * other;
        return *this;
    }
};

struct SegTree {
    int size;

    vector<Matrix> matrices;
    void init(int n) {
        size = 1;
        while (size <= n) size <<= 1;

        matrices.assign(2 * size, {1, 0, 0, 1});
    }

    void set(int i, const Matrix & m, int x, int lx, int rx) {
        if (rx - lx == 1) {
            matrices[x] = m;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, m, 2 * x + 1, lx, mid);
        }
        else {
            set(i, m, 2 * x + 2, mid, rx);
        }

        matrices[x] = matrices[2 * x + 1] * matrices[2 * x + 2];
    }
    void set(int i, const Matrix & m) {
        set(i, m, 0, 0, size);
    }

    Matrix getProduct(int l, int r, int x, int lx, int rx) {
        if (l >= rx or lx >= r) return {1, 0, 0, 1};
        if (lx >= l and rx <= r) return matrices[x];

        int mid = (lx + rx) / 2;
        Matrix m1 = getProduct(l, r, 2 * x + 1, lx, mid);
        Matrix m2 = getProduct(l, r, 2 * x + 2, mid, rx);
        return m1 * m2;
    }
    Matrix getProduct(int l, int r) {
        return getProduct(l, r, 0, 0, size);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> n >> m;

    SegTree st;
    st.init(n + 1);

    for (int i = 1; i <= n; ++i) {
        Matrix m; cin >> m.a >> m.b >> m.c >> m.d;
        st.set(i, m);
    }

    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        Matrix m = st.getProduct(l, r + 1);
        printf("%d %d\n%d %d\n\n", m.a, m.b, m.c, m.d);
    }
}