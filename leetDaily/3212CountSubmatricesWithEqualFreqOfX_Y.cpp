class Solution
{
public:
    using p = pair<int, int>;
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<p>> prefixSum(n, vector<p>(m, {0, 0}));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                prefixSum[i][j].first +=
                    (i > 0 ? prefixSum[i - 1][j].first : 0) +
                    (j > 0 ? prefixSum[i][j - 1].first : 0) -
                    (i > 0 && j > 0 ? prefixSum[i - 1][j - 1].first : 0);

                prefixSum[i][j].second +=
                    (i > 0 ? prefixSum[i - 1][j].second : 0) +
                    (j > 0 ? prefixSum[i][j - 1].second : 0) -
                    (i > 0 && j > 0 ? prefixSum[i - 1][j - 1].second : 0);

                if (grid[i][j] != '.')
                {
                    if (grid[i][j] == 'X')
                        prefixSum[i][j].first++;
                    else
                        prefixSum[i][j].second++;
                }

                if (prefixSum[i][j].first != 0 &&
                    prefixSum[i][j].first == prefixSum[i][j].second)
                    count++;
            }
        }

        return count;
    }
};