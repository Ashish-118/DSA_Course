class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {

        int n = grid.size();
        int m = grid[0].size();

        int r1 = 0, r2 = n - 1, c1 = 0, c2 = m - 1;

        while (c1 < c2 && r1 < r2)
        {

            vector<int> elements;

            for (int c = c1; c < c2; c++)
            {
                elements.push_back(grid[r1][c]);
            }

            for (int r = r1; r < r2; r++)
            {
                elements.push_back(grid[r][c2]);
            }

            for (int c = c2; c > c1; c--)
            {
                elements.push_back(grid[r2][c]);
            }

            for (int r = r2; r > r1; r--)
            {
                elements.push_back(grid[r][c1]);
            }
            int len = elements.size();

            int cycles = k % len;

            int idx = cycles;

            for (int c = c1; c < c2; c++)
            {
                grid[r1][c] = elements[idx % len];
                idx++;
            }

            for (int r = r1; r < r2; r++)
            {
                grid[r][c2] = elements[idx % len];
                idx++;
            }

            for (int c = c2; c > c1; c--)
            {
                grid[r2][c] = elements[idx % len];
                idx++;
            }

            for (int r = r2; r > r1; r--)
            {
                grid[r][c1] = elements[idx % len];
                idx++;
            }

            r1++;
            r2--;
            c1++;
            c2--;
        }

        return grid;
    }
};