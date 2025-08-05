class Solution
{
public:
    int solve(vector<int> &dp, int n)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        // think i as root node
        for (int i = 1; i <= n; i++)
        {
            ans += solve(dp, i - 1) * solve(dp, n - i);
        }

        return dp[n] = ans;
    }

    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
};

// tabulation

class Solution
{
public:
    int solve(vector<int> &dp, int n)
    {

        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            int ans = 0;
            for (int j = 1; j <= i; j++)
            {
                ans += dp[j - 1] * dp[i - j];
            }
            dp[i] = ans;
        }
        return dp[n];
    }

    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        return solve(dp, n);
    }
};