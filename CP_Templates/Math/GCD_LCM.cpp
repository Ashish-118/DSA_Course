#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm
// Returns gcd(a, b) and updates x and y such that a*x + b*y = gcd(a, b)
long long gcd_extended(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd_extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Standard GCD (can also use std::gcd in C++17)
long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Standard LCM (can also use std::lcm in C++17)
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    long long x, y;
    long long g = gcd_extended(35, 15, x, y);
    cout << "GCD: " << g << " x: " << x << " y: " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
