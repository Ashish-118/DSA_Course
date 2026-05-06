class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int mini = min(n, m);

                for (int x = 1; x < mini; x++)
                {
                    if (i + x >= n || j + x >= m)
                        break;

                    int d1 = 0;
                    int r = i, c = j;
                    for (int k = 0; k < x + 1; k++)
                    {
                        d1 += grid[r++][c++];
                    }

                    r = i + x;
                    c = j;

                    int d2 = 0;
                    for (int k = 0; k < x + 1; k++)
                    {
                        d2 += grid[r--][c++];
                    }

                    if (d1 != d2)
                        continue;
                    bool check = false;

                    for (int row = i; row <= i + x; row++)
                    {
                        int sum = 0;
                        for (int col = j; col <= j + x; col++)
                        {
                            sum += grid[row][col];
                        }
                        if (sum != d1)
                        {
                            check = true;
                            break;
                        }
                    }

                    if (check)
                        continue;

                    for (int col = j; col <= j + x; col++)
                    {
                        int sum = 0;
                        for (int row = i; row <= i + x; row++)
                        {
                            sum += grid[row][col];
                        }
                        if (sum != d1)
                        {
                            check = true;
                            break;
                        }
                    }

                    if (!check)
                        ans = max(ans, x + 1);
                }
            }
        }

        return ans;
    }
};