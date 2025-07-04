#include <unordered_map>
#include <queue>
#include <list>

bool dfs(int node, unordered_map<int, list<int>> &adj,
         unordered_map<int, bool> &visited, unordered_map<int, int> &parent)
{

    visited[node] = true;

    for (auto x : adj[node])
    {
        if (visited[x] && x != parent[node])
        {
            return true;
        }
        else if (!visited[x])
        {
            parent[x] = node;

            if (dfs(x, adj, visited, parent))
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            unordered_map<int, int> parent;
            parent[i] = -1;

            if (dfs(i, adj, visited, parent))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
