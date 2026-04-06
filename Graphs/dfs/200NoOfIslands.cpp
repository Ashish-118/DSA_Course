class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int i, int j, vector<vector<bool>> &visited,
             vector<vector<char>> &grid)
    {
        visited[i][j] = true;

        for (auto d : dir)
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            if (x_ >= 0 && x_ < visited.size() && y_ >= 0 &&
                y_ < visited[0].size() && !visited[x_][y_] &&
                grid[x_][y_] == '1')
            {
                dfs(x_, y_, visited, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i, j, visited, grid);
                    count++;
                }
            }
        }

        return count;
    }
};