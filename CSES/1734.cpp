#include <bits/stdc++.h>
using namespace std;

#define int long long

struct segTree {
    int size;
    vector<int> tree;
    
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;

        tree.assign(2 * size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or  rx <= l) return 0ll;      // Disjoint
        if (lx >= l and rx <= r) return tree[x]; // Fully inside

        int mid = (lx + rx) / 2;
        int s1 = query(l, r, 2 * x + 1, lx, mid);
        int s2 = query(l, r, 2 * x + 2, mid, rx);

        return s1 + s2;
    }
    int query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

struct Query {
    int l, r, id;
    bool operator<(const Query& other) const {
        return r < other.r;
    }
};

signed main() {
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].id = i;
    }

    sort(queries.begin(), queries.end());

    segTree st;
    st.init(n);

    map<int, int> lastPos;
    vector<int> ans(q);

    int curR = 0;
    for (const auto & qry : queries) {
        while (curR < qry.r) {
            int val = a[curR];
            if (lastPos.count(val)) {
                st.set(lastPos[val], 0);
            }
            st.set(curR, 1);
            lastPos[val] = curR;
            curR++;
        }
        ans[qry.id] = st.query(qry.l, qry.r);
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}