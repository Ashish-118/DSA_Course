class Solution
{
public:
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if (target == 0)
            return 1;
        else if (target < 0)
            return 0;

        int ways = 0;
        if (dp[target] != -1)
            return dp[target];
        for (auto x : nums)
        {
            ways += solve(nums, target - x, dp);
        }
        dp[target] = ways;
        return ways;
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
}; // this is the recursive + memoization solution

// tabulation solution
class Solution
{
public:
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {

        for (int i = 1; i <= target; i++)
        {
            for (auto x : nums)
            {
                if ((i - x) >= 0)
                {
                    dp[i] += dp[i - x];
                }
            }
        }

        return dp[target];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        return solve(nums, target, dp);
    }
};