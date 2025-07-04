class Solution
{
public:
    int solve(int n)
    {
        if (n == 0)
            return 0;
        int mini = INT_MAX;
        for (int i = 1; i <= int(sqrt(n)); i++)
        {
            mini = min(solve(n - pow(i, 2)) + 1, mini);
        }
        return mini;
    }
    int numSquares(int n)
    {
        return solve(n);
    }
}; // this is the recursive solution

// recursive + memoization solution
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        int mini = INT_MAX;
        if (dp[n] != -1)
            return dp[n];
        for (int i = 1; i <= int(sqrt(n)); i++)
        {
            mini = min(solve(n - pow(i, 2), dp) + 1, mini);
        }
        dp[n] = mini;
        return mini;
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

// tabulation solution
class Solution
{
public:
    int solve(int n, vector<int> &dp)
    {

        for (int j = 1; j <= n; j++)
        {
            int mini = INT_MAX;
            for (int i = 1; i <= int(sqrt(j)); i++)
            {
                mini = min(dp[j - pow(i, 2)] + 1, mini);
            }
            dp[j] = mini;
        }

        return dp[n];
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        return solve(n, dp);
    }
};