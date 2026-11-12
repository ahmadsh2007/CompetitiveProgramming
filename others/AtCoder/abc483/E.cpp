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

#define endl '\n'
#define int long long
#define str string // What a Python
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int MOD = 1e9 + 7;
const long long INF = 1e18;

static const int IO_SPEEDUP = [](){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

void solve() {
    int n, m; cin >> n >> m;
    vector<str> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    // sort(all(a));

    int d[3] = {0, 0, 0};
    {
        unordered_map<str, int> freq;
        for (const str& s : a) {
            freq[s]++;
        }

        for (const auto &[key, cnt] : freq) {
            d[0] += cnt * (cnt - 1) / 2;
        }
    }

    {
        for (int i = 0; i < m; ++i) {
            unordered_map<str, int> freq;
            for (str& s : a) {
                char c = s[i];
                s[i] = '*';
                freq[s]++;
                s[i] = c;
            }

            for (const auto &[key, cnt] : freq) {
                d[1] += cnt * (cnt - 1) / 2;
            }
        }
    }

    {
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                unordered_map<str, int> freq;
                for (str& s : a) {
                    char c[2] = {s[i], s[j]};
                    s[i] = s[j] = '*';
                    freq[s]++;
                    s[i] = c[0];
                    s[j] = c[1];
                }

                for (const auto &[key, cnt] : freq) {
                    d[2] += cnt * (cnt - 1) / 2;
                }
            }
        }
    }

    d[1] -= m * d[0];
    d[2] = d[2] - m * (m - 1) / 2 * d[0] - (m - 1) * d[1];
    cout << d[0] + d[1] + d[2] << endl;
}

const int TESTCASES = 0;
signed main() {
    // print("Leeking"); // Yes, it works and yes, it's Python

    int TTT = 1;
    if (TESTCASES) cin >> TTT;
    while (TTT--) solve();
    return 0;
}