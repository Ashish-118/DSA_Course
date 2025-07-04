#include <unordered_map>
#include <queue>
#include <list>

bool cyclicBFS(int src, unordered_map<int, list<int>> &adj,
               unordered_map<int, bool> &visited)
{
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto x : adj[front])
        {
            if (visited[x] && x != parent[front])
            {
                return true;
            }
            else if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
                parent[x] = front;
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
            if (cyclicBFS(i, adj, visited))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
