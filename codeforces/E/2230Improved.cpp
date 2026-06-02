#include <bits/stdc++.h>
using namespace std;

#define PARAMVECTOR vector<int> &

const int INF = 1e9 + 7;
const int LIM = 1e6 + 5;

int n, m;

void buildPrefixSuffixMin(const PARAMVECTOR news, const PARAMVECTOR users, 
                          PARAMVECTOR mn, PARAMVECTOR prefix, PARAMVECTOR suffix) {
    for (int i = 0; i < n; ++i) {
        mn[news[i]] = min(mn[news[i]], users[i]);
    }

    prefix[0] = mn[0];
    for (int i = 1; i < LIM; ++i) {
        prefix[i] = min(prefix[i - 1], mn[i]);
    }

    suffix[LIM - 1] = mn[LIM - 1];
    for (int i = LIM - 2; i >= 0; --i) {
        suffix[i] = min(suffix[i + 1], mn[i]);
    }
}

void solve() {
    cin >> n;
    vector<int> newsP(n), newsC(n);
    for (int i = 0; i < n; ++i) cin >> newsP[i];
    for (int i = 0; i < n; ++i) cin >> newsC[i];
    cin >> m;
    vector<int> usersP(m), usersC(m), usersD(m);
    for (int i = 0; i < m; ++i) cin >> usersP[i];
    for (int i = 0; i < m; ++i) cin >> usersC[i];
    for (int i = 0; i < m; ++i) cin >> usersD[i];

    int mn = INF;
    for (int i = 0; i < n; ++i) mn = min(mn, newsP[i] + newsC[i]);

    vector<int> mnCP(LIM, INF);
    vector<int> prefixCP(LIM, INF), suffixCP(LIM, INF);
    buildPrefixSuffixMin(newsP, newsC, mnCP, prefixCP, suffixCP);
    vector<int> mnPC(LIM, INF);
    vector<int> prefixPC(LIM, INF), suffixPC(LIM, INF);
    buildPrefixSuffixMin(newsC, newsP, mnPC, prefixPC, suffixPC);

    auto printAns = [&](int i) -> void {
        int ans = INF;

        if (usersP[i] > 0) {
            int limit = min(usersP[i] - 1, LIM - 1);
            int minC = prefixCP[limit];
            if (minC != INF) {
                int I = (minC < usersC[i]) ? 0 : ((minC >= usersC[i] + usersD[i]) ? usersC[i] + usersD[i] : minC);
                ans = min(ans, I);
            }
        }
        if (usersC[i] > 0) {
            int limit = min(usersC[i] - 1, LIM - 1);
            int minP = prefixPC[limit];
            if (minP != INF) {
                int I = (minP < usersP[i]) ? 0 : ((minP >= usersP[i] + usersD[i]) ? usersP[i] + usersD[i] : minP);
                ans = min(ans, I);
            }
        }
        if (usersP[i] + usersD[i] < LIM) {
            int minC = suffixCP[usersP[i] + usersD[i]];
            if (minC != INF) {
                int I = (minC < usersC[i]) ? 0 : ((minC >= usersC[i] + usersD[i]) ? usersC[i] + usersD[i] : minC);
                ans = min(ans, I + usersP[i] + usersD[i]);
            }
        }
        if (usersC[i] + usersD[i] < LIM) {
            int minP = suffixPC[usersC[i] + usersD[i]];
            if (minP != INF) {
                int I = (minP < usersP[i]) ? 0 : ((minP >= usersP[i] + usersD[i]) ? usersP[i] + usersD[i] : minP);
                ans = min(ans, I + usersC[i] + usersD[i]);
            }
        }
        if (mn != INF) ans = min(ans, mn);

        cout << ans << endl;
    };

    for (int i = 0; i < m; ++i) printAns(i);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    solve();
    return 0;
}