#include <bits/stdc++.h>
using namespace std;

// Sparse Table for Range Minimum Query (RMQ)
// Works for idempotent operations like min, max, gcd
// Time Complexity: O(N log N) build, O(1) query
template<typename T>
struct SparseTable {
    int n, K;
    vector<vector<T>> st;
    vector<int> log2_val;
    
    T merge(T a, T b) {
        return min(a, b); // Change this to max, gcd, etc.
    }

    SparseTable(const vector<T>& arr) {
        n = arr.size();
        K = 25; // max power of 2
        st.assign(K + 1, vector<T>(n));
        log2_val.assign(n + 1, 0);
        
        for (int i = 2; i <= n; i++)
            log2_val[i] = log2_val[i/2] + 1;
            
        for (int i = 0; i < n; i++)
            st[0][i] = arr[i];

        for (int j = 1; j <= K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = merge(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int L, int R) {
        int j = log2_val[R - L + 1];
        return merge(st[j][L], st[j][R - (1 << j) + 1]);
    }
};

void solve() {
    vector<long long> a = {1, 3, 5, -2, 9, 11};
    SparseTable<long long> spt(a);
    cout << spt.query(1, 4) << "\n"; // min in [1..4] -> -2
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
