class Solution
{
public:
    bool solve(int index, int n, vector<vector<int>> &dp, int target, vector<int> &nums)
    {
        if (target == 0)
            return 1;
        if (target < 0 || index >= n)
            return 0;
        if (dp[index][target] != -1)
            return dp[index][target];

        int take = solve(index + 1, n, dp, target - nums[index], nums);
        int notTake = solve(index + 1, n, dp, target, nums);

        return dp[index][target] = take or notTake;
    }
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = accumulate(begin(nums), end(nums), 0);

        vector<vector<int>> dp(n, vector<int>((totalSum / 2) + 1, -1));

        solve(0, n, dp, totalSum / 2, nums);
        int ans = 0;

        for (int target = 0; target <= totalSum / 2; target++)
        {
            if (dp[n - 1][target])
            {
                int diff = abs(totalSum - 2 * target);
                ans = min(ans, diff);
            }
        }

        return ans;
    }
};