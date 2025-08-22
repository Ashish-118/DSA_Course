class Solution
{
    int r, c;
    vector<vector<int>> dp;

public:
    bool safe(int i, int j)
    {
        return i >= 0 && j >= 0 && i < r && j < c;
    }
    int solve(int row, int col)
    {
        if (row == (r - 1) && col == (c - 1))
            return 1;
        if (dp[row][col] != -1)
            return dp[row][col];
        int down = 0;
        if (safe(row + 1, col))
        {
            down = solve(row + 1, col);
        }
        int right = 0;
        if (safe(row, col + 1))
        {
            right = solve(row, col + 1);
        }

        return dp[row][col] = down + right;
    }
    int uniquePaths(int m, int n)
    {
        r = m;
        c = n;
        dp = vector<vector<int>>(r, vector<int>(c, -1));

        return solve(0, 0);
    }
};

// tabulation method

class Solution
{
    int r, c;
    vector<vector<int>> dp;

public:
    bool safe(int i, int j)
    {
        return i >= 0 && j >= 0 && i < r && j < c;
    }

    int Tab()
    {
        dp[r - 1][c - 1] = 1;
        for (int row = r - 1; row >= 0; row--)
        {
            for (int col = c - 1; col >= 0; col--)
            {
                int down = 0;
                if (safe(row + 1, col))
                {
                    down = dp[row + 1][col];
                }
                int right = 0;
                if (safe(row, col + 1))
                {
                    right = dp[row][col + 1];
                }

                dp[row][col] += down + right;
            }
        }

        return dp[0][0];
    }
    int uniquePaths(int m, int n)
    {
        r = m;
        c = n;
        dp = vector<vector<int>>(r, vector<int>(c, 0));

        return Tab();
    }
};

// space optimized method

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

    int Tab()
    {
        curr[c - 1] = 1;
        for (int row = r - 1; row >= 0; row--)
        {
            for (int col = c - 1; col >= 0; col--)
            {
                int down = 0;
                if (safe(row + 1, col))
                {
                    down = prev[col];
                }
                int right = 0;
                if (safe(row, col + 1))
                {
                    right = curr[col + 1];
                }

                curr[col] += down + right;
            }
            prev = curr;
            curr = vector<int>(c, 0);
        }

        return prev[0];
    }
    int uniquePaths(int m, int n)
    {
        r = m;
        c = n;
        curr = vector<int>(c, 0);
        prev = vector<int>(c, 0);

        return Tab();
    }
};