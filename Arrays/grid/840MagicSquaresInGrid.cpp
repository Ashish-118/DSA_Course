class Solution
{
public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int row = 0; row < n - 2; row++)
        {
            for (int col = 0; col < m - 2; col++)
            {
                int sum1 = -1;
                bool valid = true;
                vector<bool> visited(10, false);
                for (int i = row; i <= row + 2; i++)
                {
                    int s = 0;
                    for (int j = col; j <= col + 2; j++)
                    {
                        if (grid[i][j] < 1 || grid[i][j] > 9 || visited[grid[i][j]])
                        {
                            valid &= false;
                        }
                        s += grid[i][j];
                        visited[grid[i][j]] = true;
                    }

                    if (i == row)
                        sum1 = s;
                    if (i != row && sum1 != s)
                        valid &= false;
                }

                if (!valid)
                    continue;

                for (int i = col; i <= col + 2; i++)
                {
                    int s = 0;
                    for (int j = row; j <= row + 2; j++)
                    {
                        s += grid[j][i];
                    }

                    if (sum1 != s)
                        valid &= false;
                }

                if (!valid)
                    continue;

                int d1 = 0;
                int d2 = 0;

                for (int i = 0; i < 3; i++)
                {
                    d1 += grid[row + i][col + i];
                }

                int r = row;
                int c = col + 2;

                for (int i = 0; i < 3; i++)
                {
                    d2 += grid[r++][c--];
                }

                if (d1 != sum1 || d2 != sum1)
                {
                    continue;
                }
                else
                {
                    count++;
                }
            }
        }

        return count;
    }
};