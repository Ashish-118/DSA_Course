#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

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

// Modular Inverse
long long modInverse(long long n, int m) {
    return binpow(n, m - 2, m);
}

struct Combinatorics {
    int n;
    vector<long long> fact, invFact;
    
    Combinatorics(int _n) : n(_n) {
        fact.assign(n + 1, 1);
        invFact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[n] = modInverse(fact[n], MOD);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
    
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long res = fact[n];
        res = (res * invFact[r]) % MOD;
        res = (res * invFact[n - r]) % MOD;
        return res;
    }
    
    long long nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long long res = fact[n];
        res = (res * invFact[n - r]) % MOD;
        return res;
    }
};

void solve() {
    Combinatorics C(100000);
    cout << C.nCr(5, 2) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
