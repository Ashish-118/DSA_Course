#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

// Dijkstra's Algorithm for Shortest Path in a Weighted Graph (No Negative Cycles)
struct Dijkstra {
    int n;
    vector<vector<pair<int, long long>>> adj;

    Dijkstra(int _n) {
        n = _n;
        adj.resize(n + 1);
    }

    void addEdge(int u, int v, long long w, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected) {
            adj[v].push_back({u, w});
        }
    }

    // Returns shortest path distances from source node
    vector<long long> shortestPath(int src) {
        vector<long long> dist(n + 1, INF);
        dist[src] = 0;
        
        // Min heap: {distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue; // Optimization: skip outdated pairs

            for (auto edge : adj[u]) {
                int v = edge.first;
                long long w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
    
    // Returns the path from src to dest
    vector<int> getPath(int src, int dest) {
        vector<long long> dist(n + 1, INF);
        vector<int> parent(n + 1, -1);
        dist[src] = 0;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;
            if (u == dest) break;

            for (auto edge : adj[u]) {
                int v = edge.first;
                long long w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if (dist[dest] == INF) return {}; // No path
        
        vector<int> path;
        for (int curr = dest; curr != -1; curr = parent[curr]) {
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

void solve() {
    Dijkstra graph(5);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 4);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 5, 3);
    graph.addEdge(4, 5, 1);
    
    vector<long long> dist = graph.shortestPath(1);
    for (int i = 1; i <= 5; i++) {
        cout << "Dist to " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
