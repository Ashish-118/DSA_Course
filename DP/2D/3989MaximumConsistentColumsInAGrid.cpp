class Solution
{
public:
    int t[252][252];
    int memo[252][252];

    int solve(int i, int j, int n)
    {
        if (j >= n)
        {
            return 0;
        }
        if (t[i][j] != -1)
            return t[i][j];

        int maxi = 0;
        if (i == 251 || memo[i][j])
        {
            maxi = 1 + solve(j, j + 1, n);
        }

        maxi = max(maxi, solve(i, j + 1, n));

        return t[i][j] = maxi;
    }
    int maxConsistentColumns(vector<vector<int>> &grid, int limit)
    {
        memset(t, -1, sizeof(t));
        memset(t, -1, sizeof(memo));

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = i + 1; j < m; j++)
            {
                int check = 1;
                for (int r = 0; r < n; r++)
                {
                    if (abs(grid[r][j] - grid[r][i]) > limit)
                    {
                        check = 0;
                        break;
                    }
                }

                memo[i][j] = check;
            }
        }

        int val = solve(251, 0, m);
        // here i==251 means  i will be <0 and j starts from 0, so that we can
        // evaluate 0th column as well

        return val;
    }
};