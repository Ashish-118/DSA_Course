#include <bits/stdc++.h>
using namespace std;

// Rolling Hash (String Hashing)
struct RollingHash {
    string s;
    int n;
    const long long P = 31; // 31 for lowercase english letters
    const long long M = 1e9 + 9; // Large prime
    vector<long long> p_pow;
    vector<long long> h;

    RollingHash(string _s) {
        s = _s;
        n = s.length();
        p_pow.resize(n);
        h.resize(n + 1, 0);

        p_pow[0] = 1;
        for (int i = 1; i < n; i++) 
            p_pow[i] = (p_pow[i-1] * P) % M;

        for (int i = 0; i < n; i++)
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % M;
    }

    // Hash of substring [l, r] (0-indexed)
    long long getHash(int l, int r) {
        long long current_hash = (h[r+1] + M - h[l]) % M;
        current_hash = (current_hash * binpow(p_pow[l], M - 2, M)) % M;
        return current_hash;
    }
    
    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }
};

void solve() {
    string s = "abacaba";
    RollingHash rh(s);
    if (rh.getHash(0, 2) == rh.getHash(4, 6)) { // "aba" == "aba"
        cout << "Matches!\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
