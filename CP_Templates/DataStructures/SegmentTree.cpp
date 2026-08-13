#include <bits/stdc++.h>
using namespace std;

// Segment Tree for Range Sum Query (0-indexed)
// Can be modified for Min, Max, GCD, etc.
template<typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    T identity_element;

    T merge(T a, T b) {
        return a + b; // Change this for min, max, etc.
    }

    SegmentTree(int _n, T id = 0) { // id = 0 for sum, INF for min
        n = _n;
        identity_element = id;
        tree.assign(4 * n, identity_element);
    }

    void build(const vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void build(const vector<T>& arr) {
        build(arr, 1, 0, n - 1);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val; // or tree[node] += val
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return identity_element;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        T left_query = query(2 * node, start, mid, l, r);
        T right_query = query(2 * node + 1, mid + 1, end, l, r);
        return merge(left_query, right_query);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    vector<long long> a = {1, 3, 5, 7, 9, 11};
    SegmentTree<long long> st(a.size(), 0);
    st.build(a);
    cout << st.query(1, 3) << "\n"; // Sum from index 1 to 3
    st.update(2, 6); // Update a[2] to 6
    cout << st.query(1, 3) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
