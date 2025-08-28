class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int left = INT_MAX, right = INT_MIN, top = INT_MAX, bottom = INT_MIN;

        int r = grid.size();
        int c = grid[0].size();

        for (int row = 0; row < r; row++)
        {
            for (int col = 0; col < c; col++)
            {
                if (grid[row][col])
                {
                    top = min(row, top);
                    bottom = max(row, bottom);
                    break;
                }
            }
        }

        for (int col = 0; col < c; col++)
        {
            for (int row = 0; row < r; row++)
            {

                if (grid[row][col])
                {
                    left = min(col, left);
                    right = max(col, right);
                    break;
                }
            }
        }

        return (abs(top - bottom) + 1) * (abs(left - right) + 1);
    }
};

// more optimized solution

class Solution
{
public:
    int minimumArea(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int minRow = m, maxRow = -1;
        int minCol = n, maxCol = -1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};