class Solution
{
public:
    int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp, int len1, int len2)
    {
        if (i >= len1 || j >= len2)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1, dp, len1, len2);
        }
        else
        {
            return dp[i][j] = max(solve(text1, text2, i + 1, j, dp, len1, len2), solve(text1, text2, i, j + 1, dp, len1, len2));
        }
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> lcs(text1.length(), vector<int>(text2.length(), -1));
        int len1 = text1.length(), len2 = text2.length();
        return solve(text1, text2, 0, 0, lcs, len1, len2);
    }
}; // recurssion + memoization

// tabulation or bottom up approach O(n*m) time and O(n*m) space

int longestCommonSubsequence(string text1, string text2)
{
    vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    int len1 = text1.length(), len2 = text2.length();

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    return dp[0][0];
}

// space optimized approach O(n*m) time and O(m) space

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {

        int len1 = text1.length(), len2 = text2.length();
        vector<int> prev(len2 + 1, 0);
        vector<int> curr(len2 + 1, 0);

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    curr[j] = 1 + prev[j + 1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j + 1]);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};