class Solution
{
public:
    void dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, int &countChanges, unordered_map<int, list<int>> &incoming)
    {
        visited[node] = true;

        for (auto &x : adj[node])
        {

            if (!visited[x])
            {
                countChanges++;
                dfs(x, visited, adj, countChanges, incoming);
            }
        }

        for (auto &x : incoming[node])
        {
            if (!visited[x])
            {
                dfs(x, visited, adj, countChanges, incoming);
            }
        }
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int countChanges = 0;
        vector<bool> visited(n, false);

        unordered_map<int, list<int>> adj;      // outgoing
        unordered_map<int, list<int>> incoming; // incoming
        for (auto &x : connections)
        {
            adj[x[0]].push_back(x[1]);
            incoming[x[1]].push_back(x[0]);
        }

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, adj, countChanges, incoming);
            }
        }
        return countChanges;
    }
};