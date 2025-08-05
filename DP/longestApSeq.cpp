class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j];
                if (dp[j].count(diff))
                {
                    dp[i][diff] = dp[j][diff] + 1;
                }
                else
                {
                    dp[i][diff] = 2;
                }
                res = max(res, dp[i][diff]);
            }
        }
        return res;
    }
};
