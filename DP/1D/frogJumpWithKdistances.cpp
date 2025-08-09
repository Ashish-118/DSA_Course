class Solution
{
public:
    int solve(int i, int k, vector<int> &heights, int n, vector<int> &dp)
    {
        if (i == (n - 1))
            return 0;

        int ans = INT_MAX;
        if (dp[i] != -1)
            return dp[i];
        for (int j = 1; j <= k; j++)
        {
            if ((i + j) <= n - 1)
            {
                ans = min(ans, abs(heights[i] - heights[i + j]) + solve(i + j, k, heights, n, dp));
            }
        }

        return dp[i] = ans;
    }
    int frogJump(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        return solve(0, k, heights, n, dp);
    }
};
