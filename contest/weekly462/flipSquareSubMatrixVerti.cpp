class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        int v = k;
        k--;

        for (int i = x; i < x + v && k > 0; i++)
        {
            for (int j = y; j < y + v; j++)
            {
                swap(grid[i][j], grid[i + k][j]);
            }
            k -= 2;
        }

        return grid;
    }
};
©leetcode