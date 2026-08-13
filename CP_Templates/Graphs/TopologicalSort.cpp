#include <bits/stdc++.h>
using namespace std;

// Topological Sort for Directed Acyclic Graphs (Kahn's Algorithm)
struct TopoSort {
    int n;
    vector<vector<int>> adj;
    vector<int> in_degree;

    TopoSort(int _n) {
        n = _n;
        adj.resize(n + 1);
        in_degree.assign(n + 1, 0);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        in_degree[v]++;
    }

    vector<int> sort() {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() != n) {
            return {}; // Cycle detected
        }
        return result;
    }
};

void solve() {
    TopoSort graph(4);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(1, 4);
    graph.addEdge(4, 3);
    
    vector<int> sorted = graph.sort();
    if (sorted.empty()) cout << "Cycle detected!\n";
    else {
        for (int node : sorted) cout << node << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
