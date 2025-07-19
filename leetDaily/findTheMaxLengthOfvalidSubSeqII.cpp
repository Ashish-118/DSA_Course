class Solution
{
public:
    int solve(int index, int top, int goal, vector<int> &nums, vector<int> &dp, int n, int k)
    {
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];
        int ans = 0;

        for (int i = index; i < n; i++)
        {
            if ((top + nums[i]) % k == goal || index == 0)
            {
                ans = max(ans, solve(i + 1, nums[i], goal, nums, dp, n, k) + 1);
            }
        }
        dp[index] = ans;
        return ans;
    }
    int maximumLength(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++)
        {
            vector<int> dp(n, -1);
            ans = max(solve(0, 0, i, nums, dp, n, k), ans);
        }

        return ans;
    }
}; // O(n^2 * k) solution

// optimized solution O(n^2)

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        vector<vector<int>> dp(k, vector<int>(nums.size(), 1));
        int maxSub = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                int mod = (nums[j] + nums[i]) % k;

                dp[mod][i] = max(dp[mod][i], 1 + dp[mod][j]);
                maxSub = max(maxSub, dp[mod][i]);
            }
        }
        return maxSub;
    }
};
