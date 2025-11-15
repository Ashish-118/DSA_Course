class Solution
{
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target)
    {
        int n = mat.size(), m = mat[0].size();

        // dp[i][sum] = whether this sum is possible using rows from i to end
        vector<vector<bool>> dp(n + 1, vector<bool>(5000, false));
        // (max possible sum is small: 70 * 70 = 4900 per constraints)

        dp[n][0] = true; // base case: no rows -> sum = 0

        for (int i = n - 1; i >= 0; i--)
        {
            for (int sum = 0; sum < 5000; sum++)
            {
                if (!dp[i + 1][sum])
                    continue;
                for (int val : mat[i])
                {
                    if (sum + val < 5000)
                        dp[i][sum + val] = true; // all possible sums
                }
            }
        }

        int ans = INT_MAX;
        for (int sum = 0; sum < 5000; sum++)
        {
            if (dp[0][sum])
                ans = min(ans, abs(sum - target));
        }

        return ans;
    }
};
