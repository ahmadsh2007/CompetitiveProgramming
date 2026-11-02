/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int n;
vector<vector<int>> adj;
vector<char> alive;
vector<int> sub;
 
int askSum(const vector<int>& v) {
    cout << "? 1 " << v.size();
    for (int x : v) {
        cout << ' ' << x;
    }
    cout << endl;
    int res; cin >> res;
    return res;
}
 
void toggle(int u) {
    cout << "? 2 " << u << endl;
}
 
void calcSize(int u, int p) {
    sub[u] = 1;
    for (int v : adj[u]) {
        if (v != p and alive[v]) {
            calcSize(v, u);
            sub[u] += sub[v];
        }
    }
}
 
int getCentroid(int start) {
    calcSize(start, 0);
    int total = sub[start];
    int u = start, p = 0;
    while (true) {
        int nxt = -1;
        for (int v : adj[u]) {
            if (v != p and alive[v] and sub[v] > total / 2) {
                nxt = v; break;
            }
        }
        if (nxt == -1) return u;
        p = u;
        u = nxt;
    }
}
 
bool parentIn(int c, const vector<int>& set) {
    int before = askSum(set);
    toggle(c);
    int after = askSum(set);
    int inSubtree = abs(after - before) / 2;
    return inSubtree < (int) set.size();
}
 
void solve() {
    cin >> n;
    alive.assign(n + 1, 1);
    adj.assign(n + 1, {});
    sub.assign(n + 1, 0);
 
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int start = 1, root = -1;
    while (root == -1) {
        int c = getCentroid(start);
 
        vector<int> nb;
        for (int v : adj[c]) {
            if (alive[v]) nb.push_back(v);
        }
        int d = nb.size();
 
        int l = 0, r = d;
        while (l < r) {
            int mid = (l + r) / 2;
            vector<int> set(nb.begin() + l, nb.begin() + mid + 1);
            if (parentIn(c, set)) r = mid;
            else l = mid + 1;
        }
 
        if (l == d) {
            root = c;
            break;
        }
 
        int p = nb[l];
        alive[c] = 0;
        vector<char> keep(n + 1, 0);
        vector<int> st = {p};
        keep[p] = 1;
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            for (int v : adj[u])
                if (alive[v] and !keep[v]) {
                    keep[v] = 1;
                    st.push_back(v);
                }
        }
        alive = keep;
        start = p;
    }
 
    vector<char> vis(n + 1, 0);
    vector<int> par(n + 1, 0);
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
 
    vector<int> f(n + 1);
    for (int u = 1; u <= n; ++u) {
        f[u] = askSum({u});
    }
 
    cout << "!";
    for (int u = 1; u <= n; ++u){
        cout << ' ' << (u == root ? f[u] : f[u] - f[par[u]]);
    }
    cout << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}