#define mod 1000000007

class Solution
{
public:
    vector<vector<vector<int>>> dp;

    inline pair<int, int> colRange(int col, int r1, int r2, int m, int d)
    {
        int dr = r1 - r2;
        int maxAbsDiff_for_col = sqrt((d * d) - (dr * dr));
        int L = max(0, col - maxAbsDiff_for_col);
        int R = min(col + maxAbsDiff_for_col, m - 1);
        return {L, R};
    }

    int solve(int row, int col, int TraverseCol, int n, int m,
              vector<string> &grid, int d)
    {
        if (dp[row][col][TraverseCol] != -1)
            return dp[row][col][TraverseCol];
        auto [L, R] = colRange(col, row, row, m, d);

        if (row == 0)
        {
            int ans = 1;

            for (int i = L; i <= R; i++)
            {

                if (i == col)
                    continue;
                if (grid[row][i] == '.')
                {
                    ans++;
                }
            }

            return dp[row][col][TraverseCol] = ans;
        }

        long long ans = 0;

        if (TraverseCol == 1)
        {

            for (int i = L; i <= R; i++)
            {

                if (i == col)
                    continue;
                if (grid[row][i] == '.')
                {

                    ans = (ans % mod + solve(row, i, 0, n, m, grid, d) % mod) %
                          mod;
                }
            }
        }
        auto [L2, R2] = colRange(col, row, row - 1, m, d);
        for (int i = L2; i <= R2; i++)
        {

            if (grid[row - 1][i] == '.')
            {

                ans = (ans % mod + solve(row - 1, i, 1, n, m, grid, d) % mod) %
                      mod;
            }
        }

        return dp[row][col][TraverseCol] = ans;
    }
    int numberOfRoutes(vector<string> &grid, int d)
    {

        int n = grid.size(), m = grid[0].size();

        dp = vector<vector<vector<int>>>(
            n, vector<vector<int>>(m, vector<int>(2, -1)));
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == '.')
            {
                ans = (ans + solve(n - 1, i, 1, n, m, grid, d)) % mod;
            }
        }

        return ans;
    }
};

// time complexity : O(n*m^2)
