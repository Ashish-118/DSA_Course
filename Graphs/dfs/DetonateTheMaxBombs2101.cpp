class Solution
{
public:
    int dfs(int node, unordered_map<int, list<int>> &adj,
            vector<bool> &visited)
    {
        visited[node] = true;
        int ans = 1;

        for (auto &ngb : adj[node])
        {
            if (!visited[ngb])
            {
                ans += dfs(ngb, adj, visited);
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>> &bombs)
    {

        unordered_map<int, list<int>> adj;
        int n = bombs.size();

        for (int i = 0; i < n; i++)
        {
            int x = bombs[i][0];
            int y = bombs[i][1];
            int r = bombs[i][2];

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                int h = bombs[j][0];
                int k = bombs[j][1];

                long long dx = x - h;
                long long dy = y - k;
                long long distSq = dx * dx + dy * dy;
                long long rSq = 1LL * r * r;

                if (distSq <= rSq)
                {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {

            ans = max(ans, dfs(i, adj, visited));
            fill(begin(visited), end(visited), false);
        }
        return ans;
    }
};