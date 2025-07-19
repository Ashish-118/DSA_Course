class Solution
{
public:
    int solve(vector<int> &slices, int endIndex, int n, int index, vector<vector<int>> &dp)
    {
        if (n == 0 || index > endIndex)
        {
            return 0;
        }
        if (dp[index][n] != -1)
            return dp[index][n];

        int Take = slices[index] + solve(slices, endIndex, n - 1, index + 2, dp);
        int notTake = solve(slices, endIndex, n, index + 1, dp);
        dp[index][n] = max(Take, notTake);
        return dp[index][n];
    }

    int maxSizeSlices(vector<int> &slices)
    {
        int n = slices.size();
        vector<vector<int>> dp1(n, vector<int>((n / 3) + 1, -1));
        int case1 = solve(slices, n - 2, n / 3, 0, dp1);
        vector<vector<int>> dp2(n, vector<int>((n / 3) + 1, -1));
        int case2 = solve(slices, n - 1, n / 3, 1, dp2);

        return max(case1, case2);
    }
}; // O(n^2) solution