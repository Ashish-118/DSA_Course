// approach 1
class Solution
{
public:
    long long t[100][100][101];
    vector<vector<long long>> prefixSum;

    long long solve(int row, int col, int prevRow, vector<vector<int>> &grid,
                    int n)
    {
        if (col >= n)
            return 0;

        if (t[row][col][prevRow] != -1)
            return t[row][col][prevRow];

        long long maxi = LLONG_MIN;
        long long total = 0;

        if (prevRow > 0)
        {
            int realPrev = prevRow - 1;
            total = prefixSum[realPrev][col] -
                    (col > 0 ? prefixSum[realPrev][col - 1] : 0);
        }

        long long sum = 0;

        for (int j = row; j < n; j++)
        {
            long long usingPrevBlackBox = LLONG_MIN;
            long long leavingSomeUpperElements = LLONG_MIN;
            long long usingNxtColBlackBox = LLONG_MIN;

            sum += grid[j][col];

            if (prevRow > 0 && (prevRow - 1) >= j)
            {
                usingPrevBlackBox = solve(0, col + 1, 0, grid, n); // -1 → 0
                leavingSomeUpperElements = solve(0, col + 1, j + 1, grid, n);

                if (usingPrevBlackBox != LLONG_MIN)
                    usingPrevBlackBox += sum;

                if (leavingSomeUpperElements != LLONG_MIN)
                    leavingSomeUpperElements += (total - sum);
            }

            if (col + 1 < n)
            {
                if (j + 1 == n)
                {
                    usingNxtColBlackBox = solve(0, col + 2, n, grid, n);
                }
                else
                {
                    usingNxtColBlackBox = solve(j + 1, col + 1, row, grid, n);
                }

                if (usingNxtColBlackBox != LLONG_MIN)
                    usingNxtColBlackBox += sum;
            }

            maxi = max(maxi, max({usingPrevBlackBox, usingNxtColBlackBox,
                                  leavingSomeUpperElements}));
        }

        if (row == 0)
        {
            long long ret = solve(0, col + 1, n, grid, n);
            maxi = max(maxi, ret);
        }
        else
        {
            long long ret = solve(0, col + 1, row, grid, n);
            maxi = max(maxi, ret);
        }

        return t[row][col][prevRow] = maxi;
    }

    long long maximumScore(vector<vector<int>> &grid)
    {
        int n = grid.size();
        prefixSum.assign(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                prefixSum[i][j] =
                    (i > 0 ? prefixSum[i - 1][j] : 0) +
                    (j > 0 ? prefixSum[i][j - 1] : 0) -
                    (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0) + grid[i][j];
            }
        }

        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, grid, n);
    }
};
