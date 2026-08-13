#include <bits/stdc++.h>
using namespace std;

// Prime Factorization in O(sqrt(N))
vector<pair<long long, int>> primeFactorization(long long n) {
    vector<pair<long long, int>> factors;
    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            int count = 0;
            while (n % d == 0) {
                count++;
                n /= d;
            }
            factors.push_back({d, count});
        }
    }
    if (n > 1) {
        factors.push_back({n, 1});
    }
    return factors;
}

// Fast Prime Factorization using Smallest Prime Factor (SPF) - Requires O(N) precomputation
// Best for multiple queries where N <= 10^7
struct SPF {
    int n;
    vector<int> spf;
    
    SPF(int _n) : n(_n) {
        spf.resize(n + 1);
        for (int i = 1; i <= n; i++) spf[i] = i;
        for (int p = 2; p * p <= n; p++) {
            if (spf[p] == p) {
                for (int i = p * p; i <= n; i += p) {
                    if (spf[i] == i) spf[i] = p;
                }
            }
        }
    }
    
    vector<pair<int, int>> getFactors(int x) {
        vector<pair<int, int>> factors;
        while (x != 1) {
            int p = spf[x];
            int count = 0;
            while (x % p == 0) {
                count++;
                x /= p;
            }
            factors.push_back({p, count});
        }
        return factors;
    }
};

void solve() {
    vector<pair<long long, int>> factors = primeFactorization(360);
    for (auto f : factors) {
        cout << f.first << "^" << f.second << " ";
    }
    cout << "\n";
    
    SPF spf(10000);
    auto fastFactors = spf.getFactors(360);
    // similar output
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
