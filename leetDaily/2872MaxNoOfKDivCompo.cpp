class Solution
{
public:
    int dfs(int node, unordered_map<int, list<int>> &adj, int parent,
            vector<int> &values, int k, int &count)
    {

        int remainder = values[node] % k;
        for (auto ngb : adj[node])
        {
            if (ngb != parent)
            {
                remainder =
                    (remainder + dfs(ngb, adj, node, values, k, count)) % k;
            }
        }

        if (remainder % k == 0)
        {
            count++;
        }
        return remainder % k;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k)
    {
        unordered_map<int, list<int>> adj;
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        dfs(0, adj, -1, values, k, count);
        return count;
    }
}; // time complexity: O(n) space complexity: O(n)