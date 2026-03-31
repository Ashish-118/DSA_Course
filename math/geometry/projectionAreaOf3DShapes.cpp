class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int area = 0;

        int n = grid.size();

        for (int i = 0; i < n; i++)
        { // xy plane- top view
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                {
                    area++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        { // xz plane
            int maxi = 0;
            for (int j = 0; j < n; j++)
            {
                maxi = max(maxi, grid[i][j]);
            }
            area += maxi;
        }

        for (int j = 0; j < n; j++)
        { // yz plane
            int maxi = 0;
            for (int i = 0; i < n; i++)
            {
                maxi = max(maxi, grid[i][j]);
            }
            area += maxi;
        }

        return area;
    }
};