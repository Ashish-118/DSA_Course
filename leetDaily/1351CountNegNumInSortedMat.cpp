class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int count = 0;
        int n = grid.size(), m = grid[0].size();

        int col = m - 1;

        for (int row = 0; row < n; row++)
        {
            while (col >= 0 && grid[row][col] < 0)
            {
                col--;
                count += (n - row);
            }
        }

        return count;
    }
};