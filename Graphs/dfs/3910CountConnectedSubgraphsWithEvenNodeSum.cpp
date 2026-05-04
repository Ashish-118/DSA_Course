// C++ code
// Approach: Enumerate all subsets of nodes, and for each subset, check if it forms a connected subgraph using DFS and has an even sum.
// TC: O(2^n(n+e))
// SC: O(n+e)
class Solution
{
public:
    void dfs(int u, vector<int> adj[], vector<int> &vis)
    {
        if (vis[u])
        {
            return;
        }
        vis[u] = 1;

        for (auto &it : adj[u])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }
    int evenSumSubgraphs(vector<int> &nums, vector<vector<int>> &edges)
    {
        int ans = 0;
        int n = nums.size();

        vector<int> adj[n];

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int mask = 1; mask < (1 << n); mask++)
        {
            vector<int> subsetState(n, -1); // -1 means no nodes selected
            int sum = 0;
            vector<int> subset;

            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    subsetState[i] = 0; // Nodes selected, but not visited
                    sum += nums[i];
                    subset.push_back(i);
                }
            }

            if (sum % 2 != 0)
            {
                continue;
            }

            dfs(subset[0], adj, subsetState);
            int visitedCnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (subsetState[i] == 1)
                { // Nodes selected, & visited
                    visitedCnt++;
                }
            }

            if (subset.size() == visitedCnt)
            {
                ans++;
            }
        }

        return ans;
    }
};
