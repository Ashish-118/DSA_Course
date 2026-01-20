class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                prefixSum[i][j] =
                    (i > 0 ? prefixSum[i - 1][j] : 0) +
                    (j > 0 ? prefixSum[i][j - 1] : 0) -
                    (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0) + mat[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                for (int k = 0; k < min(n - i, m - j); k++)
                {

                    int r2 = i + k, c2 = j + k;
                    int sum = prefixSum[r2][c2] -
                              (i > 0 ? prefixSum[i - 1][c2] : 0) -
                              (j > 0 ? prefixSum[r2][j - 1] : 0) +
                              (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);

                    if (sum > threshold)
                    {

                        break;
                    }
                    else
                    {
                        ans = max(ans, k + 1);
                    }
                }
            }
        }

        return ans;
    }
};