#include <bits/stdc++.h>
using namespace std;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<long long>(l, r)(rng)

int MOD1 = -1, MOD2 = -1;
int P1 = -1, P2 = -1;

static const int init_hash_var = [](){
    int ms[] = {1000000007, 1000000009, 1000000021, 1000000033, 
                1000000087, 1000000093, 1000000097, 1000000103, 
                1000000123, 1000000181, 1000000207, 1000000223};
    MOD1 = ms[rnd(0, 11)];
    MOD2 = ms[rnd(0, 11)];
    while (MOD1 == MOD2) MOD2 = ms[rnd(0, 11)];

    // Deletable:
    // P doesn't have to be prime, but it has to be a co-prime with the MOD
    int bs[] = {307, 311, 313, 317, 331, 337,
                347, 349, 353, 359, 367, 373};
    P1 = bs[rnd(0, 11)];
    P2 = bs[rnd(0, 11)];
    while (P1 == P2) P2 = bs[rnd(0, 11)];

    return 0;
}();

struct PolyHash {
    vector<long long> hash1, hash2, power1, power2;
    string s;

    PolyHash(const string &ts) {
        s = ts;

        assert(MOD1 != -1 && MOD2 != -1);
        assert(P1 != -1 && P2 != -1);
        
        int n = (int) s.size();
        hash1.assign(n + 1, 0); hash2.assign(n + 1, 0);
        power1.assign(n + 1,1); power2.assign(n + 1,1);

        for (int i = 0; i < n; ++i) {
            hash1[i + 1] = (hash1[i] * P1 + s[i]) % MOD1;
            hash2[i + 1] = (hash2[i] * P2 + s[i]) % MOD2;
            power1[i + 1] = (power1[i] * P1) % MOD1;
            power2[i + 1] = (power2[i] * P2) % MOD2;
        }
    }

    pair<long long, long long> get_hash(int l, int r) {
        long long h1 = (hash1[r + 1] - (hash1[l] * power1[r - l + 1]) % MOD1 + MOD1) % MOD1;
        long long h2 = (hash2[r + 1] - (hash2[l] * power2[r - l + 1]) % MOD2 + MOD2) % MOD2;
        return {h1, h2};
    }

    bool equal(PolyHash & o, int l1, int r1, int l2, int r2) {
        return r1 - l1 == r2 - l2 && get_hash(l1, r1) == o.get_hash(l2, r2);
    }

    bool less(PolyHash & o, int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;
        int maxLen = min(len1, len2);

        int l = 1, r = maxLen, ret = 0;        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (get_hash(l1, l1 + mid - 1) == o.get_hash(l2, l2 + mid - 1)) {
                ret = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (ret == maxLen) return len1 < len2;
        return s[l1 + ret] < o.s[l2 + ret]; 
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
        
    string s1 = "abcde", s2 = "bcd";
    PolyHash h1(s1), h2(s2);
    
    if(h1.less(h2, 1, 3, 0, 2)) {
        cout << "Matched\n";
        // "bcd" == "bcd" -> Will match properly now!
    } else cout << "WA\n";
}