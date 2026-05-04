// approach 1 - time complexity is O(n^4)
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

// approach 2 - time complexity is O(n^3)
// T.C : O(n^3)
// S.C : O(n^2)
class Solution
{
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, vector<vector<int>> &grid, vector<vector<ll>> &colPrefSum)
    {

        if (col == n)
        {
            return 0;
        }

        ll result = 0;

        if (t[prevTaken][prevHeight][col] != -1)
        {
            return t[prevTaken][prevHeight][col];
        }

        for (int height = 0; height <= n; height++)
        {
            ll prevColScore = 0;
            ll currColScore = 0;

            if (!prevTaken && col - 1 >= 0 && height > prevHeight)
            {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if (prevHeight > height)
            {
                currColScore += colPrefSum[prevHeight][col + 1] - colPrefSum[height][col + 1];
            }

            ll currColScoreTaken = currColScore + prevColScore + solve(true, height, col + 1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col + 1, grid, colPrefSum);

            result = max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;
    }

    long long maximumScore(vector<vector<int>> &grid)
    {
        n = grid.size();

        memset(t, -1, sizeof(t));

        vector<vector<ll>> colPrefSum(n + 1, vector<ll>(n + 1, 0));

        for (int col = 1; col <= n; col++)
        {
            for (int row = 1; row <= n; row++)
            {
                colPrefSum[row][col] = colPrefSum[row - 1][col] + grid[row - 1][col - 1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};