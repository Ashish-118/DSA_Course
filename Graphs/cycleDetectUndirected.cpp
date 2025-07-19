class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, unordered_map<int, bool> &visited, vector<int> &parent, bool &ans)
    {
        visited[node] = true;

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                parent[x] = node;
                dfs(x, adj, visited, parent, ans);
            }
            else if (parent[node] != x)
            {
                ans = true;
                return;
            }
        }
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        vector<int> parent(V, -1);
        bool ans = false;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && !ans)
            {
                dfs(i, adj, visited, parent, ans);
            }
        }
        return ans;
    }
};
