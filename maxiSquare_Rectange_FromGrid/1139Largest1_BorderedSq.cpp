class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid)
    {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();

        for (int r1 = 0; r1 < n; r1++)
        {
            for (int c1 = 0; c1 < m; c1++)
            {

                for (int r2 = r1, c2 = c1; r2 < n && c2 < m; r2++, c2++)
                {

                    bool valid = true;
                    for (int j = c1; j <= c2; j++)
                    {
                        if (grid[r1][j] == 0 || grid[r2][j] == 0)
                        {
                            valid &= false;
                            break;
                        }
                    }

                    if (!valid)
                        continue;

                    for (int i = r1; i <= r2; i++)
                    {
                        if (grid[i][c1] == 0 || grid[i][c2] == 0)
                        {
                            valid &= false;
                            break;
                        }
                    }

                    if (valid)
                    {
                        maxArea = max(maxArea,
                                      (abs(r1 - r2) + 1) * (abs(c1 - c2) + 1));
                    }
                }
            }
        }

        return maxArea;
    }
};