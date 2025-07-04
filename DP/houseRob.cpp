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