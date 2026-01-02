class Solution
{
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool valid(int i, int j, vector<vector<int>> &grid)
    {
        return i >= 0 && j >= 0 && i < grid.size() && !visited[i][j] &&
               j < grid[0].size() && grid[i][j] == 0;
    }

    bool solve(int i, int j, vector<vector<int>> &grid)
    {

        visited[i][j] = true;

        bool ans = (i != 0 && i != grid.size() - 1 && j != 0 &&
                    j != grid[0].size() - 1);

        for (auto d : dir)
        {
            int i_ = i + d.first;
            int j_ = j + d.second;

            if (valid(i_, j_, grid))
            {
                ans &= solve(i_, j_, grid);
            }
        }

        return ans;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (valid(i, j, grid))
                {

                    if (solve(i, j, grid))
                    {

                        count++;
                    }
                }
            }
        }

        return count;
    }
};