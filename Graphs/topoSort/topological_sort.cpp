
#include <unordered_map>
#include <list>
#include <stack>

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, st, adj);
        }
    }

    // Push the node to stack after visiting all its neighbors
    st.push(node);
}

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
    stack<int> st;

    // Call DFS for each unvisited node
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // Retrieve topological order from stack
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}