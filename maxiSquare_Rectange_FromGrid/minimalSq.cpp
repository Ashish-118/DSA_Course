class Solution
{
public:
    int solve(vector<vector<char>> &matrix, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(matrix, i, j + 1, maxi, dp);
        int down = solve(matrix, i + 1, j, maxi, dp);
        int diagonal = solve(matrix, i + 1, j + 1, maxi, dp);

        if (matrix[i][j] == '1')
        {
            int ans = 1 + min(right, min(down, diagonal));
            maxi = max(ans, maxi);
            dp[i][j] = ans;
            return ans;
        }
        else
        {
            dp[i][j] = 0;
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        solve(matrix, 0, 0, maxi, dp);
        return maxi * maxi;
    }
}; // memoization

// now this is tabulation method

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxi = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j + 1], dp[i + 1][j + 1]});
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }

        return maxi * maxi;
    }
};
// space optimization

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        int maxi = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    curr[j] = 1 + min({curr[j], curr[j + 1], next[j + 1]});
                    maxi = max(maxi, curr[j]);
                }
                else
                {
                    curr[j] = 0;
                }
            }
            next = curr;
        }

        return maxi * maxi;
    }
};
