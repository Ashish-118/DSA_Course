class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == nums1.size() || j == nums2.size())
        {
            return -1000000000; // large negative, but NOT INT_MIN
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int take = nums1[i] * nums2[j];
        int ans1 = solve(i + 1, j + 1, nums1, nums2);

        // if recursive result was valid, add it
        take = max(take, take + ans1);

        // skip options
        int skip1 = solve(i + 1, j, nums1, nums2);
        int skip2 = solve(i, j + 1, nums1, nums2);

        return dp[i][j] = max({take, skip1, skip2});
    }

    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        dp = vector<vector<int>>(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(0, 0, nums1, nums2);
    }
};
