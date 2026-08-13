#include <bits/stdc++.h>
using namespace std;

// Strongly Connected Components (SCC) using Kosaraju's Algorithm
struct SCC {
    int n;
    vector<vector<int>> adj, adj_rev;
    vector<bool> visited;
    vector<int> order, component;
    vector<vector<int>> scc_list;

    SCC(int _n) {
        n = _n;
        adj.resize(n + 1);
        adj_rev.resize(n + 1);
        visited.assign(n + 1, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj_rev[v].push_back(u);
    }

    void dfs1(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v) {
        visited[v] = true;
        component.push_back(v);
        for (int u : adj_rev[v]) {
            if (!visited[u]) dfs2(u);
        }
    }

    void build() {
        visited.assign(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs1(i);
        }

        visited.assign(n + 1, false);
        reverse(order.begin(), order.end());

        for (int v : order) {
            if (!visited[v]) {
                dfs2(v);
                scc_list.push_back(component);
                component.clear();
            }
        }
    }
};

void solve() {
    SCC graph(5);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(3, 4);
    graph.addEdge(4, 5);
    graph.build();
    
    cout << "Number of SCCs: " << graph.scc_list.size() << "\n";
    for (int i = 0; i < graph.scc_list.size(); i++) {
        cout << "SCC " << i + 1 << ": ";
        for (int node : graph.scc_list[i]) cout << node << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
