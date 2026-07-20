class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> newGrid(n, vector<int>(m, 0));
        unordered_map<int, pair<int, int>> mp;
        int totalCells = m * (n - 1) + (m - 1) + 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cellVal = i * m + j;
                int finalCellVal = 0;
                int v1 = (cellVal + k) / totalCells;
                if (v1 == 0)
                {
                    finalCellVal = cellVal + k;
                }
                else
                {
                    finalCellVal = ((cellVal + k) % totalCells);
                }

                newGrid[i][j] = finalCellVal;
                mp[cellVal] = {i, j};
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                auto loc = mp[newGrid[i][j]];

                ans[loc.first][loc.second] = grid[i][j];
            }
        }

        return ans;
    }
};


// approach 2:

class Solution
{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();

        vector<int> flattened;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                flattened.push_back(grid[i][j]);
            }
        }

        k = k % flattened.size();

        reverse(flattened.begin(), flattened.end());

        reverse(flattened.begin(), flattened.begin() + k);
        reverse(flattened.begin() + k, flattened.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cell = i * m + j;
                grid[i][j] = flattened[cell];
            }
        }

        return grid;
    }
};