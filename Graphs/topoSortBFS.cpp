
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    vector<int> indegree(v, 0);

    for (auto x : adj)
    {
        for (auto i : x.second)
        {
            indegree[i]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        ans.push_back(front);
        q.pop();

        for (auto x : adj[front])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }

    return ans;
}