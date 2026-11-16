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

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());

    auto check = [&](int mid) -> bool {
        priority_queue<int> pq(a.begin(), a.end());
        for (int t = mid - 1; t >= 0 and !pq.empty(); --t) {
            int r = pq.top();
            pq.pop();
            if (t >= 31) {
                continue;
            }

            int p = (1ll << t);
            if (r >= p) {
                if (!pq.empty() and pq.top() >= p) {
                    return false;
                }
                r -= p;
                if (r > 0) {
                    pq.push(r);
                }
            }
        }

        return pq.empty();
    };

    int l = 1, r = n + 35;
    int mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans << endl;
}

const int TESTCASES = 1;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}