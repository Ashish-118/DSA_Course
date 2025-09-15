class Solution
{
public:
    int dfs(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj)
    {
        visited[node] = true;
        int count = 1;
        for (auto &x : adj[node])
        {
            if (!visited[x])
            {
                count += dfs(x, visited, adj);
            }
        }

        return count;
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, list<int>> adj;
        vector<bool> visited(n, false);
        for (auto &x : edges)
        {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }

        long long ans = 0;
        long long PrevComponentlen = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int CurrComponentLen = dfs(i, visited, adj);
                ans += (PrevComponentlen * CurrComponentLen);
                PrevComponentlen += CurrComponentLen;
            }
        }

        return ans;
    }
};