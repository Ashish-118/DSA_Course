class Solution
{
public:
    int maxScore(vector<vector<int>> &grid)
    {
        int ans = INT_MIN;
        int n = grid.size(), m = grid[0].size();

        for (int col = 0; col < m; col++)
        {
            int maxSum = INT_MIN, currSum = grid[0][col];
            int len = 1;

            for (int row = 1; row < n; row++)
            {
                if (currSum + grid[row][col] < grid[row][col])
                {
                    maxSum = max(maxSum, currSum + grid[row][col]);
                    len = 1;
                    currSum = grid[row][col];
                }
                else
                {
                    currSum = currSum + grid[row][col];
                    len++;
                }
                if (len >= 2)
                {
                    maxSum = max(currSum, maxSum);
                }
            }

            ans = max(ans, maxSum);
        }

        for (int row = 0; row < n; row++)
        {
            int maxSum = INT_MIN, currSum = grid[row][0];
            int len = 1;
            for (int col = 1; col < m; col++)
            {
                if (currSum + grid[row][col] < grid[row][col])
                {
                    maxSum = max(maxSum, currSum + grid[row][col]);
                    len = 1;
                    currSum = grid[row][col];
                }
                else
                {
                    currSum = currSum + grid[row][col];
                    len++;
                }

                if (len >= 2)
                {
                    maxSum = max(currSum, maxSum);
                }
            }

            ans = max(ans, maxSum);
        }

        for (int row = 1; row < n - 1; row++)
        {
            for (int col = 1; col < m - 1; col++)
            {
                ans = max(ans, grid[row][col]);
            }
        }

        return ans;
    }
};