class Solution
{
public:
    bool dfs(unordered_map<int, list<int>> &adj, int node, vector<int> &types, int type)
    {
        types[node] = type;

        for (auto &x : adj[node])
        {
            if (types[x] == -1)
            {
                if (!dfs(adj, x, types, !type))
                    return false;
            }
            else if (types[x] == type)
                return false;
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {

        unordered_map<int, list<int>> adj;
        vector<int> types(n + 1, -1);
        for (auto &x : dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        bool ans = true;
        for (int i = 1; i <= n; i++)
        {
            if (types[i] == -1 && ans)
            {
                ans = ans && dfs(adj, i, types, 0);
            }
        }
        return ans;
    }
};