class Solution
{
public:
    int solve(int i, int j, vector<vector<int>> &grid, int x,
              vector<vector<vector<int>>> &dp)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return x ^ grid[i][j];
        }
        else if (i >= grid.size() || j >= grid[0].size())
        {
            return 1024;
        }
        if (dp[i][j][x] != -1)
        {
            return dp[i][j][x];
        }

        int right = solve(i, j + 1, grid, x ^ grid[i][j], dp);
        int down = solve(i + 1, j, grid, x ^ grid[i][j], dp);

        return dp[i][j][x] = min(right, down);
    }

    int minCost(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(1024, -1)));
        return solve(0, 0, grid, 0, dp);
    }
};