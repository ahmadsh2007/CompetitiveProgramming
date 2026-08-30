/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define int long long
#define str string // What a Python

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

const int N = 2e5 + 5;
vector<int> primesPowers;
vector<int> primePowersInd(N);
vector<int> spf(N);
static const int PrimePowers = []() {
    for (int i = 2; i < N; i++) spf[i] = i;
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
    for (int i = 2; i < N; i++) {
        int temp = i;
        while (temp % spf[i] == 0) temp /= spf[i];
        if (temp == 1) {
            primePowersInd[i] = (int) primesPowers.size();
            primesPowers.push_back(i);
        }
    }
    return 0;
}();

template<typename T, typename Op = std::plus<T>>
class SegTree {
    /*
    Recursive init
    SegTree<long long> sum_tree(a, 0LL); // Defaults to std::plus
    SegTree<long long, std::max<long long>> max_tree(a, -1e18);
    SegTree<int, decltype([](const int & x, const int & y) -> int { return gcd(x, y); })> maximumModuloEquality(d, 0ll);
    */
private:
    int size;
    vector<T> tree;
    T def;
    Op op;

    void build(int x, int lx, int rx, const vector<T>& a) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) tree[x] = a[lx];
            return;
        }
        int mid = lx + (rx - lx) / 2;
        build(2 * x + 1, lx, mid, a);
        build(2 * x + 2, mid, rx, a);
        tree[x] = op(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, T v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int mid = lx + (rx - lx) / 2;
        if (i < mid) update(i, v, 2 * x + 1, lx, mid);
        else         update(i, v, 2 * x + 2, mid, rx);
        tree[x] = op(tree[2 * x + 1], tree[2 * x + 2]);
    }

    T query(int l, int r, int x, int lx, int rx) {
        if (lx >= r or  rx <= l) return def;     // Disjoint
        if (lx >= l and rx <= r) return tree[x]; // Fully inside
        int mid = lx + (rx - lx) / 2;
        return op(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
    }

public:
    SegTree(int n, T def = T()) : def(def) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, def);
    }
    
    SegTree(const vector<T>& a, T def = T()) : SegTree(a.size(), def) {
        build(0, 0, size, a);
    }

    void update(int i, T v) {
        update(i, v, 0, 0, size);
    }
    void add(int i, T v) {
        update(i, op(get(i), v));
    }

    // [l, r)
    T query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    T get(int i) {
        return query(i, i + 1);
    }
};

struct Query {
    int pp;
    int lPlus;
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int mx = n;
    for (int pp : primesPowers) {
        if (pp > n) {
            mx = pp;
            break;
        }
    }
    
    vector<vector<int>> obs(mx + 1);
    vector<vector<Query>> queries(mx);

    for (int pp : primesPowers) {
        if (pp > mx) break;
        obs[pp].push_back(0);
    }

    auto addFactors = [&](int val, int idx) {
        while (val > 1) {
            int p = spf[val];
            int curPP = p;
            while (val % p == 0) { 
                if (curPP <= mx) obs[curPP].push_back(idx);
                curPP *= p;
                val /= p;
            }
        }
    };

    for (int i = 1; i <= n; i++) addFactors(a[i], i);
    for (int pp : primesPowers) {
        if (pp > mx) break;
        obs[pp].push_back(n + 1);
        
        for (int j = 0; j < (int) obs[pp].size() - 1; j++) {
            int L = obs[pp][j], R = obs[pp][j + 1];
            if (L + 1 <= R - 1) {
                queries[R - 1].push_back({pp, L + 1});
            }
        }
        obs[pp].clear();
    }

    vector<int> zeros((int) primesPowers.size());
    SegTree<int, decltype([](const int & x, const int & y) -> int { return min(x, y); })> st(zeros, 1e9);
    
    vector<bool> possible(mx + 1);
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        while (val > 1) {
            int p = spf[val];
            int curPP = p;
            while (val % p == 0) {
                if (curPP <= mx) st.update(primePowersInd[curPP], i);
                curPP *= p;
                val /= p;
            }
        }

        for (auto& q : queries[i]) {
            if (q.pp == 2) { 
                possible[2] = 1; 
                continue; 
            }
            if (st.query(0, primePowersInd[q.pp]) >= q.lPlus) {
                possible[q.pp] = 1;
            }
        }
    }

    vector<int> ans;
    for (int pp : primesPowers) {
        if (pp > mx) break;
        if (possible[pp]) ans.push_back(pp);
    }

    cout << (int) ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
        cout << ans[i] << " \n"[i == (int) ans.size() - 1];
    }
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}