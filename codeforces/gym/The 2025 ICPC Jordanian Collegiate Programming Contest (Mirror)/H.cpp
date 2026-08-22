#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

struct Node {
    vector<int> arr;
    vector<int> pre;
};

struct SegTree {
    int size;
    vector<Node> tree;

    SegTree(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, {{}, {}});
    }

    void set(int i, int v, int x, int lx, int rx) {
        tree[x].arr.push_back(v);
        int last = tree[x].pre.empty() ? 0 : tree[x].pre.back();
        tree[x].pre.push_back(last + v);

        if (rx - lx == 1) return;

        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int k, int x, int lx, int rx) {
        if (lx >= r or rx <= l) return 0;
        if (rx <= r and lx >= l) {
            int idx = upper_bound(tree[x].arr.begin(), tree[x].arr.end(), k) - tree[x].arr.begin();
            return idx > 0 ? tree[x].pre[idx - 1] : 0;
        }
        if (rx - lx <= 1) return 0;

        int mid = (lx + rx) / 2;
        int m1 = query(l, r, k, 2 * x + 1, lx, mid);
        int m2 = query(l, r, k, 2 * x + 2, mid, rx);
        return m1 + m2;
    }
    int query(int l, int r, int k) {
        return query(l, r, k, 0, 0, size);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    SegTree st(n + 1);
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) {
        st.set(a[i].second, a[i].first);
    }

    int q; cin >> q;
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        r++;
        cout << st.query(l, r, k) << endl;
    }
}