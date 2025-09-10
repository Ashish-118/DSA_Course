class Solution
{
public:
    int dfs(int row, int c1, int c2, vector<vector<int>> &grid,
            vector<int> &dir, int n, int m, vector<vector<vector<int>>> &dp)
    {
        if (row >= n || c1 < 0 || c2 < 0 || c1 >= m || c2 >= m)
            return 0;

        if (dp[row][c1][c2] != -1)
            return dp[row][c1][c2];

        int collect = (c1 == c2 ? grid[row][c1] : grid[row][c1] + grid[row][c2]);

        int maxi = INT_MIN;

        for (int i = 0; i < dir.size(); i++)
        {
            int r1_dir = c1 + dir[i];

            for (int j = 0; j < dir.size(); j++)
            {
                int r2_dir = c2 + dir[j];

                maxi = max(maxi, dfs(row + 1, r1_dir, r2_dir, grid, dir, n, m, dp));
            }
        }

        return dp[row][c1][c2] = collect + maxi;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<int> dir = {0, -1, 1};

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        int ans = dfs(0, 0, m - 1, grid, dir, n, m, dp);

        return ans;
    }
}; // O(n*m^2) time and space complexity

// space optimized

class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> dir = {0, -1, 1};

        vector<vector<int>> prev(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        for (int row = n - 1; row >= 0; row--)
        {
            for (int c1 = 0; c1 < m; c1++)
            {
                for (int c2 = 0; c2 < m; c2++)
                {
                    int collect = (c1 == c2 ? grid[row][c1] : grid[row][c1] + grid[row][c2]);
                    int maxi = INT_MIN;

                    for (int i = 0; i < dir.size(); i++)
                    {
                        int r1 = c1 + dir[i];
                        for (int j = 0; j < dir.size(); j++)
                        {
                            int r2 = c2 + dir[j];

                            if (r1 >= 0 && r2 >= 0 && r1 < m && r2 < m)
                            {
                                maxi = max(maxi, prev[r1][r2]);
                            }
                        }
                    }

                    curr[c1][c2] = collect + maxi;
                }
            }
            prev = curr;
        }

        return prev[0][m - 1]; // start from (0,0) and (0,m-1)
    }
};
