class Solution
{
public:
    vector<long long> dp;

    long long solve(int i, vector<int> &nums, vector<int> &colors)
    {
        if (i >= nums.size())
            return 0;
        else if (i == nums.size() - 1)
            return nums[i];

        if (dp[i] != -1)
            return dp[i];

        long long take = 0;
        if (colors[i + 1] == colors[i])
        {
            take = nums[i] + solve(i + 2, nums, colors);
        }
        else
            take = nums[i] + solve(i + 1, nums, colors);

        long long notTake = solve(i + 1, nums, colors);

        return dp[i] = max(take, notTake);
    }

    long long rob(vector<int> &nums, vector<int> &colors)
    {
        int n = nums.size();
        dp = vector<long long>(n, -1);

        return solve(0, nums, colors);
    }
};