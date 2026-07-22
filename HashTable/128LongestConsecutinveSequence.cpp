class Solution
{
public:
    unordered_map<int, list<int>> adj;
    unordered_set<int> visited;

    int dfs(int node)
    {
        visited.insert(node);

        int count = 1;

        for (auto &ngb : adj[node])
        {
            if (visited.find(ngb) == visited.end())
            {
                count += dfs(ngb);
            }
        }

        return count;
    }
    int longestConsecutive(vector<int> &nums)
    {

        for (auto x : nums)
        {
            adj[x] = {};
        }

        for (auto x : nums)
        {
            if (adj.count(x + 1))
            {
                adj[x].push_back(x + 1);
                adj[x + 1].push_back(x);
            }
        }

        int ans = 0;

        for (auto x : nums)
        {
            if (visited.find(x) == visited.end())
            {
                ans = max(ans, dfs(x));
            }
        }

        return ans;
    }
};