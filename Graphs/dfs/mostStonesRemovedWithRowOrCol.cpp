class Solution
{
public:
    int dfs(vector<vector<int>> &adj, vector<bool> &visited, int node)
    {
        visited[node] = true;
        int count = 0;
        for (auto &x : adj[node])
        {
            if (!visited[x])
            {
                count += dfs(adj, visited, x);
            }
        }
        return count + 1;
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();

        vector<vector<int>> adjacencyList(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                ans += (dfs(adjacencyList, visited, i) - 1);
            }
        }

        return ans;
    }
};