class Solution
{
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        ll total = 0;
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                total += grid[i][j];
            }
        }

        ll verticalSum = 0;

        for (int col = 0; col < m - 1; col++)
        {
            for (int row = 0; row < n; row++)
            {
                verticalSum += grid[row][col];
            }

            if (total - verticalSum == verticalSum)
            {
                return true;
            }
        }

        ll horizontalSum = 0;

        for (int row = 0; row < n - 1; row++)
        {
            for (int col = 0; col < m; col++)
            {
                horizontalSum += grid[row][col];
            }
            if (total - horizontalSum == horizontalSum)
            {
                return true;
            }
        }

        return false;
    }
};

// Optimized version using prefix sums

class Solution
{
public:
    using ll = long long;
    bool canPartitionGrid(vector<vector<int>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>> prefixSum(n, vector<ll>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefixSum[i][j] =
                    grid[i][j] + (j > 0 ? prefixSum[i][j - 1] : 0) +
                    (i > 0 ? prefixSum[i - 1][j] : 0) -
                    (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);
            }
        }

        if (prefixSum[n - 1][m - 1] & 1)
            return false;

        for (int col = 0; col < m - 1; col++)
        {

            if (prefixSum[n - 1][m - 1] - prefixSum[n - 1][col] ==
                prefixSum[n - 1][col])
            {

                return true;
            }
        }

        for (int row = 0; row < n - 1; row++)
        {

            if (prefixSum[n - 1][m - 1] - prefixSum[row][m - 1] ==
                prefixSum[row][m - 1])
            {

                return true;
            }
        }

        return false;
    }
};