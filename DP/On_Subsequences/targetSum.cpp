class Solution
{
public:
    unordered_map<int, unordered_map<int, int>> dp;

    int solve(vector<int> &nums, int target, int index, int n, int sum)
    {
        if (index >= n)
        {
            if (target == sum)
                return 1;
            else
                return 0;
        }
        if (dp.count(index) && dp[index].count(sum))
            return dp[index][sum];

        // use -
        int sub = solve(nums, target, index + 1, n, sum - nums[index]);
        int add = solve(nums, target, index + 1, n, sum + nums[index]);

        return dp[index][sum] = sub + add;
    }

    int Tab(vector<int> &nums, int target)
    {
        int n = nums.size();
        dp[n][target] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int sum = 0;)
        }
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();

        return solve(nums, target, 0, n, 0);
    }
};

// class Solution {
public:
int findTargetSumWays(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    vector<int> dp(2 * totalSum + 1, 0);

    // Initialize the first row of the DP table
    dp[nums[0] + totalSum] = 1;   // Adding nums[0]
    dp[-nums[0] + totalSum] += 1; // Subtracting nums[0]

    // Fill the DP table
    for (int index = 1; index < nums.size(); index++)
    {
        vector<int> next(2 * totalSum + 1, 0);
        for (int sum = -totalSum; sum <= totalSum; sum++)
        {
            if (dp[sum + totalSum] > 0)
            {
                next[sum + nums[index] + totalSum] += dp[sum + totalSum];
                next[sum - nums[index] + totalSum] += dp[sum + totalSum];
            }
        }
        dp = next;
    }

    // Return the result if the target is within the valid range
    return abs(target) > totalSum ? 0 : dp[target + totalSum];
};