class Solution
{
public:
    int solve(int n, int i, vector<int> &height, vector<int> &dp)
    {
        if (i == n - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int one = solve(n, i + 1, height, dp) + abs(height[i] - height[i + 1]);

        int two = INT_MAX;
        if (i < n - 2)
        {
            two = solve(n, i + 2, height, dp) + abs(height[i] - height[i + 2]);
        }

        return dp[i] = min(one, two); // Store result in dp
    }

    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1); // Initialize memoization array
        return solve(n, 0, height, dp);
    }
};
