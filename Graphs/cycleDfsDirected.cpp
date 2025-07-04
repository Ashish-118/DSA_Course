#include <unordered_map>
#include <queue>
#include <list>

bool dfsCycle(int src, unordered_map<int, list<int>> &adj,
              unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
{

    visited[src] = true;
    dfsVisited[src] = true;

    for (auto x : adj[src])
    {
        if (!visited[x])
        {
            if (dfsCycle(x, adj, visited, dfsVisited))
                return true;
        }
        else if (visited[x] && dfsVisited[x])
            return true;
    }

    dfsVisited[src] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{

    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (dfsCycle(i, adj, visited, dfsVisited))
                return true;
        }
    }
    return false;
}