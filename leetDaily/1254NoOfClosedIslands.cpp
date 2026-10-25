class Solution
{
public:
    vector<vector<bool>> visited;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool solve(int i, int j, vector<vector<int>> &grid)
    {
        if (grid[i][j] == 1)
        {
            return true;
        }

        visited[i][j] = true;

        bool ans = true;

        for (auto &d : dir)
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            if (x_ < 0 || x_ >= grid.size() || y_ < 0 || y_ >= grid[0].size())
            {
                ans &= false;
            }
            else if (!visited[x_][y_])
            {
                ans &= solve(x_, y_, grid);
            }
        }

        return ans;
    }
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
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