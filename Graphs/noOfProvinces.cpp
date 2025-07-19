class Solution
{
public:
    void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
    {

        visited[node] = true;

        for (auto x : adj[node])
        {
            if (!visited[x])
            {
                dfs(x, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        unordered_map<int, list<int>> adj;
        int v = isConnected.size();
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, adj, visited);
            }
        }

        return ans;
    }
};