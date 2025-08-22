class Solution
{
    int r, c;
    vector<long long> curr;
    vector<long long> prev;

public:
    bool safe(int i, int j, vector<vector<int>> &obstacleGrid)
    {
        return i >= 0 && j >= 0 && i < r && j < c && obstacleGrid[i][j] == 0;
    }

    long long Tab(vector<vector<int>> &obstacleGrid)
    {
        curr[c - 1] = 1;
        for (int row = r - 1; row >= 0; row--)
        {
            for (int col = c - 1; col >= 0; col--)
            {
                if (row == r - 1 && col == c - 1)
                    continue;
                long long down = 0;
                if (safe(row + 1, col, obstacleGrid))
                {
                    down = prev[col];
                }
                long long right = 0;
                if (safe(row, col + 1, obstacleGrid))
                {
                    right = curr[col + 1];
                }

                curr[col] += (down + right);
            }
            prev = curr;
            curr = vector<long long>(c, 0);
        }

        return prev[0];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        r = obstacleGrid.size();
        c = obstacleGrid[0].size();
        curr = vector<long long>(c, 0);
        prev = vector<long long>(c, 0);

        if (obstacleGrid[0][0])
            return 0;
        return (int)Tab(obstacleGrid); // cast back to int for return
    }
};
