class Solution
{
public:
    int solve(int target, vector<int> &arr, int index, vector<vector<int>> &dp)
    {

        if (target == 0 && index == arr.size())
            return 1;
        if (target < 0 || index >= arr.size())
            return 0;

        if (dp[index][target] != -1)
            return dp[index][target];

        int Take = solve(target - arr[index], arr, index + 1, dp);
        int NotTake = solve(target, arr, index + 1, dp);

        return dp[index][target] = Take + NotTake;
    }
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return solve(target, arr, 0, dp);
    }
};