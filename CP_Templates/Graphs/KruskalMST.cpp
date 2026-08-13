#include <bits/stdc++.h>
using namespace std;

// Minimum Spanning Tree using Kruskal's Algorithm
struct DSU {
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v;
    long long weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

struct Kruskal {
    int n;
    vector<Edge> edges;
    
    Kruskal(int _n) { n = _n; }
    
    void addEdge(int u, int v, long long w) {
        edges.push_back({u, v, w});
    }
    
    long long findMST() {
        long long mst_cost = 0;
        vector<Edge> result;
        DSU dsu(n);
        
        sort(edges.begin(), edges.end());
        
        for (Edge e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mst_cost += e.weight;
                result.push_back(e);
            }
        }
        
        // If graph is not fully connected, check result.size() == n - 1
        if (result.size() != n - 1) {
            return -1; // Or return INF, indicating no MST
        }
        return mst_cost;
    }
};

void solve() {
    Kruskal graph(5);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 5, 3);
    graph.addEdge(4, 5, 1);
    
    cout << graph.findMST() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
