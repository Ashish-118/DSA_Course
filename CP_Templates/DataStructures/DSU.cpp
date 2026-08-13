#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (Union Find) with Path Compression and Union by Size
struct DSU {
    vector<int> parent;
    vector<int> size;
    int components;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path compression
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            // Union by size
            if (size[root_i] < size[root_j])
                swap(root_i, root_j);
            
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            components--;
            return true; // Successfully united
        }
        return false; // Already in the same set
    }
    
    int getSize(int i) {
        return size[find(i)];
    }
};

void solve() {
    DSU dsu(5);
    dsu.unite(0, 1);
    dsu.unite(2, 3);
    if (dsu.find(1) == dsu.find(0)) {
        cout << "Connected\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
