class Solution
{
public:
    double solve(int n, int k, int maxPts, int score, vector<double> &dp)
    {
        if (score >= k)
        {
            return score <= n ? 1.0 : 0;
        }

        if (dp[score] != -1.0)
            return dp[score];

        double ans = 0.0;
        for (int i = 1; i <= maxPts; i++)
        {
            ans += (1.0 / maxPts) * solve(n, k, maxPts, score + i, dp);
        }
        return dp[score] = ans;
    }
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> dp(n, -1.0);
        return solve(n, k, maxPts, 0, dp);
    }
};

// tabulation method

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        vector<double> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= maxPts; j++)
            {
                // dp[i-j] -> dp[i]
                if (i >= j && i - j < k)
                {
                    dp[i] += dp[i - j] / maxPts;
                }
            }
        }
        double ans = 0;
        for (int i = k; i <= n; i++)
        {
            ans += dp[i];
        }
        return ans;
    }
};