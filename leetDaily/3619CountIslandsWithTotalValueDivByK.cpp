class Solution
{
public:
    vector<vector<int>> visited;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    void dfs(int i, int j, long long int &sum, vector<vector<int>> &grid)
    {

        visited[i][j] = true;

        for (auto &d : dir)
        {
            int x_ = i + d.first;
            int y_ = j + d.second;

            if (x_ >= 0 && y_ >= 0 && x_ < grid.size() && y_ < grid[0].size() &&
                grid[x_][y_] != 0 && !visited[x_][y_])
            {
                sum += grid[x_][y_];
                dfs(x_, y_, sum, grid);
            }
        }
    }
    int countIslands(vector<vector<int>> &grid, int k)
    {
        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<int>(m, false));

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] != 0 && !visited[i][j])
                {
                    long long int sum = grid[i][j];
                    dfs(i, j, sum, grid);
                    if (sum % k == 0)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};