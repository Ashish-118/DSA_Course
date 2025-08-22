class Solution
{
    int r, c;

public:
    bool safe(int i, int j)
    {
        return i >= 0 && j >= 0 && i < r && j < c;
    }
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (row == (r - 1) && col == (c - 1))
            return grid[row][col];

        if (dp[row][col] != -1)
            return dp[row][col];
        int down = INT_MAX;
        if (safe(row + 1, col))
        {
            down = grid[row][col] + solve(row + 1, col, grid, dp);
        }
        int right = INT_MAX;
        if (safe(row, col + 1))
        {
            right = grid[row][col] + solve(row, col + 1, grid, dp);
        }

        return dp[row][col] = min(down, right);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        r = grid.size();
        c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        return solve(0, 0, grid, dp);
    }
};

// tabulation + space optimised method

class Solution
{
    int r, c;
    vector<int> curr;
    vector<int> prev;

public:
    bool safe(int i, int j)
    {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    int Tab(vector<vector<int>> &grid)
    {
        curr[c - 1] = grid[r - 1][c - 1];
        for (int row = r - 1; row >= 0; row--)
        {
            for (int col = c - 1; col >= 0; col--)
            {
                if (row == r - 1 && col == c - 1)
                    continue;

                int down = INT_MAX;
                if (safe(row + 1, col))
                {
                    down = prev[col];
                }
                int right = INT_MAX;
                if (safe(row, col + 1))
                {
                    right = curr[col + 1];
                }

                curr[col] = min(down, right) + grid[row][col];
            }
            prev = curr;
            curr = vector<int>(c, 0);
        }

        return prev[0];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        r = grid.size();
        c = grid[0].size();
        curr = vector<int>(c, 0);
        prev = vector<int>(c, 0);
        return Tab(grid);
    }
};