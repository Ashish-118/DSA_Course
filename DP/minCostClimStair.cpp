class Solution
{
public:
    int solve(vector<int> &cost, vector<int> &dp, int n)
    {
        if (n == 0)
            return cost[0];
        else if (n == 1)
            return cost[1];

        if (dp[n] != -1)
            return dp[n];

        dp[n] = cost[n] + min(solve(cost, dp, n - 1), solve(cost, dp, n - 2));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        int ans = min(solve(cost, dp, n - 1), solve(cost, dp, n - 2));
        return ans;
    }
};

///

class Solution
{
public:
    int solve(vector<int> &cost, int start, int n)
    {
        int prev1 = cost[0];
        int prev2 = cost[1];
        if (n <= 2)
            return min(prev1, prev2);
        for (int i = 2; i <= start; i++)
        {
            int curr = min(prev1, prev2) + cost[i];
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int ans = min(solve(cost, n - 1, n), solve(cost, n - 2, n));
        return ans;
    }
};