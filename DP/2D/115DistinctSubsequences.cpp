class Solution
{
public:
    long long dp[1001][1001];

    // int solve(int i, int j, string s, string t) {
    //     if (j >= t.length()) {
    //         return 1;
    //     } else if (i >= s.length()) {
    //         return 0;
    //     }

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int count = 0;

    //     if (s[i] == t[j]) {
    //         count += solve(i + 1, j + 1, s, t);
    //     }

    //     count += solve(i + 1, j, s, t);

    //     return dp[i][j] = count;
    // }
    int numDistinct(string s, string t)
    {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,0,s,t);

        memset(dp, 0, sizeof(dp));

        int n1 = s.length(), n2 = t.length();

        for (int i = 0; i <= n1; i++)
        {
            dp[i][n2] = 1;
        }

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                int count = 0;

                if (s[i] == t[j])
                {
                    count += dp[i + 1][j + 1];
                }

                count += dp[i + 1][j];

                dp[i][j] = count;
            }
        }

        return dp[0][0];
    }
};