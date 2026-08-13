#include <bits/stdc++.h>
using namespace std;

// Tree LCA (Lowest Common Ancestor) and Binary Lifting
// Time Complexity: O(N log N) preprocessing, O(log N) per query
struct LCA {
    int n, l;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;

    LCA(int _n) {
        n = _n;
        adj.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        depth.resize(n + 1);
        timer = 0;
        l = ceil(log2(n + 1));
        up.assign(n + 1, vector<int>(l + 1));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int v, int p, int d) {
        tin[v] = ++timer;
        up[v][0] = p;
        depth[v] = d;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, d + 1);
        }

        tout[v] = ++timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    
    int dist(int u, int v) {
        int ancestor = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[ancestor];
    }

    void build(int root = 1) {
        dfs(root, root, 0); // Root is its own parent
    }
};

void solve() {
    LCA tree(5);
    tree.addEdge(1, 2);
    tree.addEdge(1, 3);
    tree.addEdge(2, 4);
    tree.addEdge(2, 5);
    tree.build(1);
    
    cout << tree.lca(4, 5) << "\n"; // 2
    cout << tree.dist(4, 3) << "\n"; // 3
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
