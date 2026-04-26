class Solution
{
public:
    vector<vector<int>> visited;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

    bool solve(int i, int j, vector<vector<char>> &grid, pair<int, int> parent,
               char c)
    {
        visited[i][j] = true;

        for (auto d : dir)
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            if (x_ >= 0 && y_ >= 0 && x_ < grid.size() && y_ < grid[0].size())
            {
                if (parent == make_pair(x_, y_) || grid[x_][y_] != c)
                    continue;

                if (!visited[x_][y_])
                {
                    if (solve(x_, y_, grid, {i, j}, c))
                        return true;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited.assign(n, vector<int>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                {
                    cout << i << " " << j << endl;
                    if (solve(i, j, grid, {i, j}, grid[i][j]))
                        return true;
                }
            }
        }

        return false;
    }
};