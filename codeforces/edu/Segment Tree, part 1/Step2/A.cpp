#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int size;
    vector<long long> sums;
    vector<long long> maxSums;
    vector<long long> prefix;
    vector<long long> suffix;
    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        sums.assign(2 * size, 0ll);
        maxSums.assign(2 * size, 0ll);
        prefix.assign(2 * size, 0ll);
        suffix.assign(2 * size, 0ll);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;
            maxSums[x] = max(0ll, (long long) v);
            prefix[x] = max(0ll, (long long) v);
            suffix[x] = max(0ll, (long long) v);
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
        maxSums[x] = max({maxSums[2 * x + 1], maxSums[2 * x + 2], prefix[2 * x + 2] + suffix[2 * x + 1]});
        prefix[x] = max({prefix[2 * x + 1], sums[2 * x + 1] + prefix[2 * x + 2]});
        suffix[x] = max({suffix[2 * x + 2], sums[2 * x + 2] + suffix[2 * x + 1]});
        return;
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long maxSum() {
        return maxSums[0];
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    SegTree st;
    st.init(n);

    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        st.set(i, v);
    }
    
    while (m--) {
        cout << st.maxSum() << endl;
        int i, v; cin >> i >> v;
        st.set(i, v);
    }
    cout << st.maxSum() << endl;
}