/*
       بسم الله الرحمن الرحيم
    أسالك يا الله التوفيق والنجاح
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct Tree {
    int id;
    int n;
    int notInTheSetVertex;
    int leaf;
    vector<vector<int>> adj;
    Tree(int n) {
        this->n = n;
        adj.assign(n + 1, {});
        notInTheSetVertex = 1;
        leaf = 1;
    }
};

void solve() {
    int k; cin >> k;
    vector<Tree> forest;
    for (int t = 0; t < k; ++t) {
        int n; cin >> n;
        Tree tree(n);
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            tree.adj[u].push_back(v);
            tree.adj[v].push_back(u);
        }

        tree.id = t + 1;
        for (int i = 1; i <= n; ++i) {
            if ((int) tree.adj[i].size() == 1) {
                tree.leaf = i;
                break;
            }
        }

        if (n >= 2) {
            tree.notInTheSetVertex = tree.adj[tree.leaf][0];
        }
        else {
            tree.notInTheSetVertex = 1;
        }

        forest.push_back(move(tree));
    }

    vector<int> single, nonSingle;
    for (int i = 0; i < k; ++i) {
        if (forest[i].n == 1) {
            single.push_back(i);
        }
        else {
            nonSingle.push_back(i);
        }
    }

    if (nonSingle.empty()) {
        for (int i = 1; i < k; ++i) {
            cout << forest[i].id << ' ' << forest[i].notInTheSetVertex << ' ' << forest[0].id << ' ' << forest[0].notInTheSetVertex << endl;
        }
        return;
    }

    for (int i = 0; i + 1 < (int) nonSingle.size(); ++i) {
        cout << forest[nonSingle[i]].id << ' ' << forest[nonSingle[i]].notInTheSetVertex << ' ' << forest[nonSingle[i + 1]].id << " " << forest[nonSingle[i + 1]].notInTheSetVertex << endl;
    }

    for (int i = 0; i < (int) single.size(); ++i) {
        cout << forest[single[i]].id << " 1 " << forest[nonSingle[0]].id << ' ' << forest[nonSingle[0]].notInTheSetVertex << endl;
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