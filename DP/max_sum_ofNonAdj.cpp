// #include <bits/stdc++.h>

// int solve(vector<int> &nums, vector<int> &dp, int n)
// {
//     if (n < 0)
//         return 0;
//     if (n == 0)
//         return nums[0];

//     if (dp[n] != -1)
//         return dp[n];

//     int inc = solve(nums, dp, n - 2) + nums[n];
//     int exc = solve(nums, dp, n - 1) + 0;

//     dp[n] = max(inc, exc);
//     return dp[n];
// }

// int maximumNonAdjacentSum(vector<int> &nums)
// {
//     int len = nums.size();
//     vector<int> dp(len + 1, -1);

//     return solve(nums, dp, len - 1);
// }

//// Tabulation methoid

int solve(vector<int> &nums, vector<int> &dp)
{
    int len = nums.size();
    vector<int> dp(len, 0);
    dp[0] = nums[0];

    for (int i = 0; i < len; i++)
    {
        int inc = dp[i - 2] + nums[i];
        int exc = dp[i - 1] + 0;
        dp[i] = max(inc, exc);
    }

    return dp[len - 1];
}