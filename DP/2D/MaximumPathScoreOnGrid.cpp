class Solution
{
public:
    // example: 3D vector (careful with memory/time to initialize)
    vector<vector<vector<int>>> dp;

    int cost(int x)
    {
        if (x == 0)
            return 0;
        else
            return 1;
    }
    int solve(int i, int j, vector<vector<int>> &grid, int k, int n, int m)
    {
        if (i == n - 1 && j == m - 1)
            return grid[i][j];
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int right = INT_MIN, down = INT_MIN;

        if (j + 1 < m && k - cost(grid[i][j + 1]) >= 0)
        {
            int v1 = solve(i, j + 1, grid, k - cost(grid[i][j + 1]), n, m);
            if (v1 == INT_MIN)
            {
                right = v1;
            }
            else
            {
                right = grid[i][j] +
                        solve(i, j + 1, grid, k - cost(grid[i][j + 1]), n, m);
            }
        }
        if (i + 1 < n && k - cost(grid[i + 1][j]) >= 0)
        {
            int v2 = solve(i + 1, j, grid, k - cost(grid[i + 1][j]), n, m);
            if (v2 == INT_MIN)
            {
                down = v2;
            }
            else
            {
                down = grid[i][j] +
                       solve(i + 1, j, grid, k - cost(grid[i + 1][j]), n, m);
            }
        }

        return dp[i][j][k] = max(right, down);
    }
    int maxPathScore(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        dp = vector<vector<vector<int>>>(
            n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        int ans = solve(0, 0, grid, k, n, m);
        return ans == INT_MIN ? -1 : ans;
    }
};
©leetcode