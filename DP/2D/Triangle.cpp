class Solution
{
public:
    int solve(int row, int i, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (row >= triangle.size() || i >= triangle[row].size())
            return 0;
        if (dp[row][i] != INT_MIN)
        {

            return dp[row][i];
        }

        int left = solve(row + 1, i, triangle, dp);
        int right = solve(row + 1, i + 1, triangle, dp);

        return dp[row][i] = min(left, right) + triangle[row][i];
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int res = INT_MAX;
        int row = triangle.size();
        int m = triangle[row - 1].size();
        vector<vector<int>> dp(row, vector<int>(m, INT_MIN));

        for (int col = 0; col < triangle[0].size(); col++)
        {
            res = min(res, solve(0, col, triangle, dp));
        }

        return res;
    }
};

// space optimised

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {

        int n = triangle.size();
        int m = triangle[n - 1].size();

        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        for (int row = n - 1; row >= 0; row--)
        {
            for (int i = 0; i < triangle[row].size(); i++)
            {
                int left = prev[i];
                int right = prev[i + 1];

                curr[i] = min(left, right) + triangle[row][i];
            }
            prev = curr;
        }

        return prev[0];
    }
};