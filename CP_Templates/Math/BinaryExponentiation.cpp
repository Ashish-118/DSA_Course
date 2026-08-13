#include <bits/stdc++.h>
using namespace std;

// Binary Exponentiation (Fast Power)
// Computes (a ^ b) % m in O(log b)
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Computes (a ^ b) exactly (watch out for overflow)
long long binpow_exact(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    cout << binpow(2, 10, 1e9 + 7) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
