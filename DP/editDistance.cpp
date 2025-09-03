
// recurrsion plus memoization
class Solution
{
public:
    int solve(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        // base cases
        if (i == word1.size())
            return word2.size() - j; // need to insert remaining
        if (j == word2.size())
            return word1.size() - i; // need to delete remaining

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
        }
        else
        {
            int insertOp = 1 + solve(i, j + 1, word1, word2, dp);
            int deleteOp = 1 + solve(i + 1, j, word1, word2, dp);
            int replaceOp = 1 + solve(i + 1, j + 1, word1, word2, dp);
            return dp[i][j] = min({insertOp, deleteOp, replaceOp});
        }
    }

    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2, dp);
    };

    // tabulation or bottom up approach

    class Solution
    {
    public:
        int minDistance(string word1, string word2)
        {
            int n = word1.size(), m = word2.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

            // base cases
            for (int i = 0; i <= n; i++)
                dp[i][m] = n - i; // delete all remaining
            for (int j = 0; j <= m; j++)
                dp[n][j] = m - j; // insert all remaining

            // fill table from bottom-right
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    if (word1[i] == word2[j])
                    {
                        dp[i][j] = dp[i + 1][j + 1]; // chars match → no cost
                    }
                    else
                    {
                        int insertOp = 1 + dp[i][j + 1];
                        int deleteOp = 1 + dp[i + 1][j];
                        int replaceOp = 1 + dp[i + 1][j + 1];
                        dp[i][j] = min({insertOp, deleteOp, replaceOp});
                    }
                }
            }

            return dp[0][0];
        }
    };

    // space optimization method

    class Solution
    {
    public:
        int minDistance(string word1, string word2)
        {
            int n = word1.size(), m = word2.size();

            vector<int> curr(m + 1, 0);
            vector<int> prev(m + 1, 0);
            // base cases

            for (int j = 0; j <= m; j++)
                prev[j] = m - j; // insert all remaining
            prev[m] = 0;
            // fill table from bottom-right
            for (int i = n - 1; i >= 0; i--)
            {
                curr[m] = n - i; // catch for deleting all remaining
                for (int j = m - 1; j >= 0; j--)
                {

                    if (word1[i] == word2[j])
                    {
                        curr[j] = prev[j + 1]; // chars match → no cost
                    }
                    else
                    {
                        int insertOp = 1 + curr[j + 1];
                        int deleteOp = 1 + prev[j];
                        int replaceOp = 1 + prev[j + 1];
                        curr[j] = min({insertOp, deleteOp, replaceOp});
                    }
                }

                prev = curr;
            }

            return prev[0];
        }
    };
