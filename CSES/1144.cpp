/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

// Vector input/output operators
// I wish I could just do `v = list(map(int, input().split()))` instead of this boilerplate
template<class T>
istream& operator>>(istream& in, vector<T>& v){
    for(auto& x:v) in>>x;
    return in;
}
// I wish I could just do `print(*v)` instead of this boilerplate
template<class T>
ostream& operator<<(ostream& out, vector<T>& v){
    for(auto& x:v) out<<x<<' ';
    return out;
}

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).begin(), (x).rend()
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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct SegTree {
    int size;
    vector<int> salary;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        salary.assign(2 * size, 0);
    }

    void set(int i, int process, int x, int lx, int rx) {
        if (rx - lx == 1) {
            salary[x] += process;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) {
            set(i, process, 2 * x + 1, lx, mid);
        }
        else {
            set(i, process, 2 * x + 2, mid, rx);
        }
        salary[x] = salary[2 * x + 1] + salary[2 * x + 2];
    }
    void set(int i, int process) {
        set(i, process, 0, 0, size);
    }

    int getSum(int l, int r, int x, int lx, int rx) {
        if (lx >= r or l >= rx) return 0;
        if (lx >= l and rx<= r) return salary[x];

        int mid = lx + (rx - lx) / 2;
        return getSum(l, r, 2 * x + 1, lx, mid) + getSum(l, r, 2 * x + 2, mid, rx);
    }
    int getSum(int l, int r) {
        return getSum(l, r, 0, 0, size);
    }
};

struct Query {
    char op;
    int a, b;
};

void solve() {
    int n, q; cin >> n >> q;

    vector<int> p(n);
    set<int> allValues; 
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        allValues.insert(p[i]);
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].op >> queries[i].a >> queries[i].b;
        if (queries[i].op == '!') {
            allValues.insert(queries[i].b);
        }
    }

    vector<int> vals(all(allValues));
    auto getRank = [&](int val) {
        return lower_bound(vals.begin(), vals.end(), val) - vals.begin();
    };

    SegTree st;
    st.init(vals.size() + 1);

    for (int i = 0; i < n; ++i) {
        st.set(getRank(p[i]), 1);
    }

    for (int i = 0; i < q; ++i) {
        if (queries[i].op == '!') {
            st.set(getRank(p[queries[i].a - 1]), -1);
            p[queries[i].a - 1] = queries[i].b;
            st.set(getRank(p[queries[i].a - 1]), 1);
        } else {
            int L = lower_bound(vals.begin(), vals.end(), queries[i].a) - vals.begin();
            int R = upper_bound(vals.begin(), vals.end(), queries[i].b) - vals.begin();
            cout << st.getSum(L, R) << endl;
        }
    }
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}