#include <bits/stdc++.h>
using namespace std;

// Segment Tree with Lazy Propagation for Range Updates and Range Queries
// Example: Range Add Update, Range Sum Query
template<typename T>
struct SegmentTreeLazy {
    int n;
    vector<T> tree, lazy;

    SegmentTreeLazy(int _n) {
        n = _n;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            // Update current node
            tree[node] += lazy[node] * (end - start + 1);
            
            // Push lazy to children if not a leaf
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            
            // Clear current lazy
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, T val) {
        push(node, start, end);
        
        if (start > end || start > r || end < l)
            return;
            
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateRange(int l, int r, T val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    T queryRange(int node, int start, int end, int l, int r) {
        push(node, start, end);
        
        if (start > end || start > r || end < l)
            return 0; // Identity
            
        if (start >= l && end <= r)
            return tree[node];
            
        int mid = (start + end) / 2;
        T p1 = queryRange(2 * node, start, mid, l, r);
        T p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

    T queryRange(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n = 5;
    SegmentTreeLazy<long long> st(n);
    st.updateRange(0, 2, 5); // Add 5 to [0..2]
    st.updateRange(1, 4, 2); // Add 2 to [1..4]
    cout << st.queryRange(1, 2) << "\n"; // Sum in [1..2]
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
