class Solution
{
public:
    int longestCommonSubstr(string &s1, string &s2)
    {
        // your code here

        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s1[i] == s2[j])
                {
                    dp[i][j] = 1 + (i >= 1 && j >= 1 ? dp[i - 1][j - 1] : 0);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};