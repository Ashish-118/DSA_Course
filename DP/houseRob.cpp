class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        map<int, int> dp;

        dp[0] = nums[0];

        for (int i = 1; i < len; i++)
        {
            int inc = dp[i - 2] + nums[i];
            int exc = dp[i - 1] + 0;
            dp[i] = max(inc, exc);
        }
        return dp[len - 1];
    }
};

// space optimised

class Solution
{
public:
    int solve(vector<int> &nums, int n)
    {
        int prev1 = 0, prev2 = 0;

        for (int i = 0; i < n; i++)
        {
            int Take = (i >= 2 ? nums[i] + prev1 : nums[i]);
            int notTake = (i >= 1 ? 0 + prev2 : 0);
            prev1 = prev2;
            prev2 = max(Take, notTake);
        }

        return prev2;
    }
    int rob(vector<int> &nums)
    {

        int n = nums.size();

        return solve(nums, n);
    }
};