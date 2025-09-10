class Solution
{
public:
    pair<int, int> dfs_first(int count, int node, vector<int> &BelowthNodes, unordered_map<int, list<int>> &adj, vector<bool> &visited)
    {
        visited[node] = true;
        int nodes = 0;
        int sum = 0;
        for (auto ngb : adj[node])
        {
            if (!visited[ngb])
            {
                auto ans = dfs_first(count + 1, ngb, BelowthNodes, adj, visited);
                nodes += ans.first;
                sum += ans.second;
            }
        }
        BelowthNodes[node] = nodes + 1;
        return {nodes + 1, sum + count};
    }

    void dfs_second(vector<int> &result, int parent, unordered_map<int, list<int>> &adj, int n, vector<int> &BelowthNodes, vector<bool> &visited)
    {
        visited[parent] = true;
        for (auto &x : adj[parent])
        {
            if (!visited[x])
            {
                result[x] = result[parent] - BelowthNodes[x] + (n - BelowthNodes[x]);
                dfs_second(result, x, adj, n, BelowthNodes, visited);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {

        vector<int> BelowthNodes(n, 0);
        vector<int> result(n, 0);

        unordered_map<int, list<int>> adj;
        for (auto &x : edges)
        {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }
        vector<bool> visited(n, false);
        auto ans = dfs_first(0, 0, BelowthNodes, adj, visited);
        result[0] = ans.second;

        visited.assign(n, false); // reset size = n, all false

        dfs_second(result, 0, adj, n, BelowthNodes, visited);

        return result;
    }
}; // O(N) time complexity, O(N) space complexity