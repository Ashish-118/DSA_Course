#include <bits/stdc++.h>
using namespace std;

// Standard Sieve of Eratosthenes
struct Sieve {
    int n;
    vector<bool> is_prime;
    vector<int> primes;

    Sieve(int _n) : n(_n) {
        is_prime.assign(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    is_prime[i] = false;
            }
        }
        for (int p = 2; p <= n; p++) {
            if (is_prime[p]) {
                primes.push_back(p);
            }
        }
    }
};

void solve() {
    Sieve sieve(1000000);
    // sieve.is_prime[x] gives if x is prime
    // sieve.primes contains all primes <= n
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
