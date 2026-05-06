class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefixSum[i][j] = grid[i][j] +
                                  (j > 0 ? prefixSum[i][j - 1] : 0) +
                                  (i > 0 ? prefixSum[i - 1][j] : 0) -
                                  (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);

                if (prefixSum[i][j] <= k)
                    count++;
            }
        }

        return count;
    }
};