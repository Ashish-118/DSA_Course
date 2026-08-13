#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree (Binary Indexed Tree) for Point Update and Range Query (1-indexed)
// Note: If you have 0-indexed arrays, pass (index + 1) to update and query
template<typename T>
struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<T>& a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) {
            update(i + 1, a[i]);
        }
    }

    void update(int idx, T delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    T query(int idx) {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve() {
    vector<long long> a = {1, 3, 5, 7, 9, 11};
    FenwickTree<long long> bit(a);
    cout << bit.query(1, 3) << "\n"; // Sum of elements at indices 1, 2, 3 (1-indexed) -> 1+3+5 = 9
    bit.update(2, 2); // Add 2 to a[1] (1-indexed index 2)
    cout << bit.query(1, 3) << "\n"; // Sum becomes 1+5+5 = 11
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
